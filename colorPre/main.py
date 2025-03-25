from sklearn.ensemble import RandomForestRegressor
from sklearn.multioutput import MultiOutputRegressor
import numpy as np
import ds
import reverseDs
import followDs
from joblib import dump



# 初始化模型

model = MultiOutputRegressor(
    RandomForestRegressor(
        n_estimators=150,
        max_depth=6,
        min_samples_split=3,
        random_state=42
    )
)

#model.fit(ds.x_train, ds.y_train)
#model.fit(reverseDs.x_train_reverse,reverseDs.y_train_reverse)
model.fit(followDs.x_train_follow,followDs.y_train_follow)
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
#dump(model,"reverseModel.pkl")
dump(model,"followModel.pkl")
hex_color = rgb_to_hex(predicted_rgb)  # 示例输出：#E3B432
print(hex_color)
