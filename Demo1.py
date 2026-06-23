import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# ==============================
# 1. Tạo dữ liệu mẫu (doanh thu)
# ==============================
np.random.seed(0)
so_ngay = 100

# Tạo dữ liệu có xu hướng tăng + nhiễu
du_lieu = np.linspace(50, 100, so_ngay) + np.random.normal(0, 5, so_ngay)

df = pd.DataFrame({
    'Ngay': pd.date_range(start='2024-01-01', periods=so_ngay),
    'DoanhThu': du_lieu
})

# ==============================
# 2. Moving Average Forecast
# ==============================
window = 5
df['DuDoan'] = df['DoanhThu'].rolling(window=window).mean()

# ==============================
# 3. Dự đoán tương lai (5 ngày)
# ==============================
so_ngay_du_doan = 5
gia_tri_cuoi = df['DoanhThu'].tail(window).mean()

du_doan_tuong_lai = []

for i in range(so_ngay_du_doan):
    du_doan_tuong_lai.append(gia_tri_cuoi)

ngay_tuong_lai = pd.date_range(start=df['Ngay'].iloc[-1], periods=so_ngay_du_doan+1)[1:]

df_future = pd.DataFrame({
    'Ngay': ngay_tuong_lai,
    'DuDoan': du_doan_tuong_lai
})

# ==============================
# 4. Vẽ biểu đồ
# ==============================
plt.figure()

plt.plot(df['Ngay'], df['DoanhThu'], label='Dữ liệu thực tế')
plt.plot(df['Ngay'], df['DuDoan'], linestyle='--', label='Moving Average')
plt.plot(df_future['Ngay'], df_future['DuDoan'], linestyle='--', label='Dự đoán tương lai')

plt.xlabel('Thời gian')
plt.ylabel('Giá trị')
plt.title('Demo Forecasting với Moving Average')
plt.legend()

plt.show()