# Chương trình mô phỏng trạng thái của các thiết bị điện cơ

## Giới thiệu

Chương trình mô phỏng hoạt động các thiết bị điện-cơ trong nhà: **bóng đèn**, **quạt (nhiều tốc độ)**, **điều hòa** (Cool / Heat / Dry, nhiệt 18–30°C).  
Tính năng chính: ID ngẫu nhiên cho thiết bị, mật khẩu kết nối (có đổi), kiểm tra mật khẩu khi điều khiển, hẹn giờ bật/tắt, cập nhật tiêu thụ điện khi thay đổi trạng thái, thống kê giờ hoạt động (ngày/tháng/năm), và quản lý **nhà → phòng → thiết bị**.

---

## Phần cứng

- ESP32 Dev Module  
- Relay 5V (1 hoặc 4 kênh)  
- OLED (I²C)  
- LED 5mm (đỏ, xanh) + điện trở 220Ω  
- Breadboard, dây Dupont (Đực–Cái / Đực–Đực)  
- Tải mô phỏng (bóng LED/quạt nhỏ)

---

## Cài đặt (ngắn gọn)

1) Tải Arduino IDE
```bash
https://www.arduino.cc/en/software
```

2) Thêm ESP32 board URL vào Arduino IDE
- File → Preferences → "Additional Boards Manager URLs"
- Dán:
```bash
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

3) Cài ESP32 board
- Tools → Board → Boards Manager → tìm "esp32" → Install
- Chọn Tools → Board → "ESP32 Dev Module"

4) Nếu không thấy cổng USB (Tools → Port), cài driver USB:
```bash
- CH340: http://www.wch.cn/downloads/CH341SER_EXE.html
- CP2102: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
```

---

## Ghép nối thiết bị

1) Kết nối OLED với ESP32
```bash
OLED VCC → ESP32 VIN (hoặc 3.3V)  
OLED GND → ESP32 GND  
OLED SCL → ESP32 GPIO 22  
OLED SDA → ESP32 GPIO 21  
```

2) Kết nối Relay Module với ESP32
```bash
Relay DC+ → ESP32 VIN (5V)  
Relay DC- → ESP32 GND  
Relay IN1 → ESP32 GPIO 5  
Relay IN2 → ESP32 GPIO 18  
Relay IN3 → ESP32 GPIO 19  
Relay IN4 → ESP32 GPIO 23  
```

3) Kết nối LED + Điện trở 220Ω
```bash
LED Đỏ:  Chân dài → 220Ω → GPIO 13  
         Chân ngắn → GND  

LED Xanh: Chân dài → 220Ω → GPIO 12  
          Chân ngắn → GND  
```

4) Ghi chú
- Đảm bảo nguồn 5V cho relay đủ dòng.  
- Kiểm tra loại relay (active LOW / active HIGH).  
- Thử trước với tải nhỏ để đảm bảo an toàn.
---
