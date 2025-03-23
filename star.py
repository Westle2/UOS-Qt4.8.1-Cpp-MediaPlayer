#!/usr/bin/env python
# -*- coding: utf-8 -*-
import asyncio
import hashlib
import hmac
import base64
import json
import time
import logging
import sys
from urllib.parse import quote
from pydub import AudioSegment
import websockets

# 配置API信息
app_id = "3e98e979"
api_key = "146853e87965f64bbe0ac4e3701d3841"

class Client:
    def __init__(self):
        self.base_url = "ws://rtasr.xfyun.cn/v1/ws"
        self.end_tag = "{\"end\": true}"
        self.ws = None  # WebSocket 连接对象

    async def connect(self):
        """建立 WebSocket 连接"""
        ts = str(int(time.time()))
        base_string = hashlib.md5((app_id + ts).encode('utf-8')).hexdigest()
        signa = base64.b64encode(hmac.new(api_key.encode('utf-8'), base_string.encode('utf-8'), hashlib.sha1).digest()).decode('utf-8')

        ws_url = f"{self.base_url}?appid={app_id}&ts={ts}&signa={quote(signa)}"
        self.ws = await websockets.connect(ws_url)
        print("WebSocket connected")
        asyncio.create_task(self.recv())  # 启动接收任务

    def convert_to_pcm(self, input_file, output_file):
        """
        转换音频文件为16kHz 单声道 PCM 格式
        """
        audio = AudioSegment.from_file(input_file)
        audio = audio.set_frame_rate(16000).set_channels(1).set_sample_width(2)  # 设置为16kHz单声道
        audio.export(output_file, format="raw")
        print(f"File saved as PCM at {output_file}")

    async def send(self, file_path):
        """发送音频数据"""
        if not self.ws:
            print("WebSocket not connected!")
            return

        pcm_file_path = file_path + ".pcm"
        self.convert_to_pcm(file_path, pcm_file_path)
        file_object = open(pcm_file_path, 'rb')  # 直接用普通 open
        try:
            chunk = file_object.read(1280)
            while chunk:
                await self.ws.send(chunk)
                chunk = file_object.read(1280)
                time.sleep(0.04)
        finally:
            file_object.close()
            await self.ws.close()  # 发送完后关闭 WebSocket

        await self.ws.send(self.end_tag.encode('utf-8'))
        print("send end tag success")

    async def recv(self):
        """接收 WebSocket 数据"""
        try:
            async for message in self.ws:
                result_dict = json.loads(message)

                if result_dict["action"] == "started":
                    print("handshake success, result: " + message)

                if result_dict["action"] == "result":
                    data = json.loads(result_dict["data"])

                    words = [cw["w"] for rt in data.get("cn", {}).get("st", {}).get("rt", [])
                                 for ws in rt.get("ws", [])
                                 for cw in ws.get("cw", [])]

                    latest_text = "".join(words)
                    print("\r", latest_text, end="", flush=True)  # 覆盖上一行输出

                if result_dict["action"] == "error":
                    print("rtasr error: " + message)
                    await self.ws.close()
                    return
        except websockets.ConnectionClosed:
            print("Connection closed")

    async def close(self):
        """关闭 WebSocket 连接"""
        if self.ws:
            await self.ws.close()
            print("Connection closed")

async def main():
    """异步主函数"""
    if len(sys.argv) < 2:
        print("Please provide the file path.")
        sys.exit(1)

    file_path = sys.argv[1]
    client = Client()
    await client.connect()
    await client.send(file_path)


if __name__ == '__main__':
    logging.basicConfig()
    asyncio.run(main())
