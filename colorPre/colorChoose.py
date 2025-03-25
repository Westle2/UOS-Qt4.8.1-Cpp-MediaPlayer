from joblib import load
import numpy as np


def rgb_to_hex(rgb):
    clamped = np.clip(rgb, 0, 255).astype(int)
    return "#{:02X}{:02X}{:02X}".format(*clamped)


def predict_color(emotion_ratios, model_path="model.pkl"):
    """
    根据输入的情绪比例列表预测对应的十六进制颜色代码。

    参数:
    emotion_ratios (list): 包含 5 个情绪比例的列表，顺序为 [中性, 快乐, 悲伤, 愤怒, 恐惧]
    model_path (str): 保存的模型文件的路径，默认为 "model.pkl"

    返回:
    str: 预测得到的十六进制颜色代码
    """
    # 加载模型
    model = load(model_path)
    # 将输入转换为适合模型的格式
    input_data = np.array(emotion_ratios).reshape(1, -1)
    # 进行预测
    predicted_rgb = model.predict(input_data)[0]
    # 转换为十六进制颜色代码
    hex_color = rgb_to_hex(predicted_rgb)
    return hex_color



# 获取用户输入的情绪比例
to_be_pre = []
row0 = []
for i in range(5):
    row0.append(float(input(f"请输入第 {i + 1} 个情绪比例（顺序：中性, 快乐, 悲伤, 愤怒, 恐惧）: ")))
to_be_pre.append(row0)
# 调用预测函数
result = predict_color(row0)
print(f"预测的十六进制颜色代码为: {result}")
=======
import sys
import numpy as np
from joblib import load
import joblib

def predict_color(emotion_ratios, model_path="colorPre/model.pkl"):
    """
    根据情绪比例预测颜色（RGB）。
    :param emotion_ratios: 5 个情绪比例的列表 [中性, 快乐, 悲伤, 愤怒, 恐惧]
    :param model_path: 训练好的模型文件
    :return: 预测的 RGB 颜色值
    """
    model = joblib.load(model_path)  # 载入模型
    input_data = np.array(emotion_ratios).reshape(1, -1)
    predicted_rgb = model.predict(input_data)[0]
    return predicted_rgb.astype(int)  # 确保是整数类型

if __name__ == "__main__":
    # **1. 参数检查**
    if len(sys.argv) < 6:
        print("Error: Missing arguments", file=sys.stderr)
        sys.exit(1)

    try:
        neutrality = float(sys.argv[1])
        happiness = float(sys.argv[2])
        sadness = float(sys.argv[3])
        anger = float(sys.argv[4])
        fear = float(sys.argv[5])
    except ValueError:
        print("Error: 输入必须是数字", file=sys.stderr)
        sys.exit(1)

    emotion_ratios = [neutrality, happiness, sadness, anger, fear]

    # **2. 打印调试信息**
    print(f"Received: {neutrality}, {happiness}, {sadness}, {anger}, {fear}", file=sys.stderr)
    sys.stderr.flush()  # 确保 stderr 立即输出

    # **3. 进行颜色预测**
    predicted_rgb = predict_color(emotion_ratios)

    # **4. 输出 RGB 结果**
    print(f"{predicted_rgb[0]} {predicted_rgb[1]} {predicted_rgb[2]}")
    sys.stdout.flush()  # 确保 QProcess 能立即读取

