// Test_All_Basic.ino
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

// Component pins
#define RELAY1 5
#define RELAY2 18
#define RELAY3 19
#define RELAY4 23
#define LED_RED 13
#define LED_GREEN 12

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Device states
bool relay1State = false;
bool relay2State = false;
bool relay3State = false;
bool relay4State = false;
bool ledRedState = false;
bool ledGreenState = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Smart Home System Starting...");
  
  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Error!");
    for(;;);
  }
  
  // Setup pins
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  // Initialize all OFF
  allOff();
  
  // Display welcome
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("SMART HOME");
  display.println("System Ready!");
  display.display();
  delay(2000);
}

void loop() {
  // Test sequence
  for(int i = 1; i <= 6; i++) {
    testDevice(i);
    delay(1500);
  }
  
  // All OFF
  allOff();
  updateDisplay();
  delay(2000);
}

void testDevice(int device) {
  // Reset all states
  relay1State = false;
  relay2State = false;
  relay3State = false;
  relay4State = false;
  ledRedState = false;
  ledGreenState = false;
  
  switch(device) {
    case 1:
      relay1State = true;
      digitalWrite(RELAY1, LOW);
      Serial.println("Relay 1 ON - Living Room Light");
      break;
    case 2:
      relay2State = true;
      digitalWrite(RELAY2, LOW);
      Serial.println("Relay 2 ON - Bedroom Light");
      break;
    case 3:
      relay3State = true;
      digitalWrite(RELAY3, LOW);
      Serial.println("Relay 3 ON - Air Conditioner");
      break;
    case 4:
      relay4State = true;
      digitalWrite(RELAY4, LOW);
      Serial.println("Relay 4 ON - Fan");
      break;
    case 5:
      ledRedState = true;
      digitalWrite(LED_RED, HIGH);
      Serial.println("Red LED ON - Alert");
      break;
    case 6:
      ledGreenState = true;
      digitalWrite(LED_GREEN, HIGH);
      Serial.println("Green LED ON - Status OK");
      break;
  }
  
  updateDisplay();
  delay(1000);
  
  // Turn OFF after test
  allOff();
}

void allOff() {
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("DEVICE STATUS:");
  display.println("--------------");
  
  // Display relay states
  display.print("R1:");
  display.print(relay1State ? "ON " : "OFF ");
  display.print("R2:");
  display.println(relay2State ? "ON" : "OFF");
  
  display.print("R3:");
  display.print(relay3State ? "ON " : "OFF ");
  display.print("R4:");
  display.println(relay4State ? "ON" : "OFF");
  
  // Display LED states
  display.print("LED R:");
  display.print(ledRedState ? "ON " : "OFF ");
  display.print("G:");
  display.println(ledGreenState ? "ON" : "OFF");
  
  // Show system time
  display.print("Time: ");
  display.print(millis()/1000);
  display.println("s");
  
  display.display();
}