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
