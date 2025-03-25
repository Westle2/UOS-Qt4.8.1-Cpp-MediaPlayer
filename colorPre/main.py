from sklearn.ensemble import RandomForestRegressor
from sklearn.multioutput import MultiOutputRegressor
import numpy as np
import ds
from joblib import dump
# 模拟训练数据（需替换为真实数据）

# 情绪比例顺序：[中性, 快乐, 悲伤, 愤怒, 恐惧]



# 初始化模型

model = MultiOutputRegressor(
    RandomForestRegressor(
        n_estimators=150,
        max_depth=6,
        min_samples_split=3,
        random_state=42
    )
)

model.fit(ds.x_train, ds.y_train)
to_be_pre=[]
row0=[]
for i in range(5):
    row0.append(float(input()))
to_be_pre.append(row0)
predicted_rgb=model.predict(to_be_pre)[0]
# 转换为十六进制

def rgb_to_hex(rgb):
    clamped = np.clip(rgb, 0, 255).astype(int)
    return "#{:02X}{:02X}{:02X}".format(*clamped)
dump(model,"model.pkl")
hex_color = rgb_to_hex(predicted_rgb)  # 示例输出：#E3B432
print(hex_color)
from sklearn.ensemble import RandomForestRegressor
from sklearn.multioutput import MultiOutputRegressor
import numpy as np
import ds
from joblib import dump
# 模拟训练数据（需替换为真实数据）

# 情绪比例顺序：[中性, 快乐, 悲伤, 愤怒, 恐惧]



# 初始化模型

model = MultiOutputRegressor(
    RandomForestRegressor(
        n_estimators=150,
        max_depth=6,
        min_samples_split=3,
        random_state=42
    )
)

model.fit(ds.x_train, ds.y_train)
to_be_pre=[]
row0=[]
for i in range(5):
    row0.append(float(input()))
to_be_pre.append(row0)
predicted_rgb=model.predict(to_be_pre)[0]
# 转换为十六进制

def rgb_to_hex(rgb):
    clamped = np.clip(rgb, 0, 255).astype(int)
    return "#{:02X}{:02X}{:02X}".format(*clamped)
dump(model,"colorPre/model.pkl")
hex_color = rgb_to_hex(predicted_rgb)  # 示例输出：#E3B432
print(hex_color)
