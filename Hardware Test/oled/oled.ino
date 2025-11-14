#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Khai báo đối tượng display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting OLED test...");
  
  // Khởi tạo OLED với địa chỉ 0x3C
  // Nếu không hiển thị, thử đổi thành 0x3F
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("OLED không tìm thấy!");
    for(;;); // Dừng lại nếu lỗi
  }
  
  Serial.println("OLED OK!");
  
  // Clear buffer
  display.clearDisplay();
  
  // Set text properties
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  
  // Display text
  display.println("Smart Home System");
  display.println("----------------");
  display.println("OLED Test: OK");
  display.println("ESP32 Ready!");
  
  // Show on OLED
  display.display();
}

void loop() {
  // Hiển thị thời gian chạy
  display.fillRect(0, 40, 128, 24, BLACK); // Xóa vùng hiển thị time
  display.setCursor(0, 40);
  display.print("Uptime: ");
  display.print(millis() / 1000);
  display.println(" sec");
  display.display();
  
  delay(1000);
}