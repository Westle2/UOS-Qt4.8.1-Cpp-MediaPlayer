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
