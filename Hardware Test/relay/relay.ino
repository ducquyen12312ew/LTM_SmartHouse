#define RELAY1 5
#define RELAY2 18
#define RELAY3 19
#define RELAY4 23

void setup() {
  Serial.begin(115200);
  Serial.println("Test Relay Module 4 Channel");
  
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  
  delay(1000);
}

void loop() {
  Serial.println("Relay 1 ON");
  digitalWrite(RELAY1, LOW);   // ON
  delay(1000);
  digitalWrite(RELAY1, HIGH);  // OFF
  delay(500);
  
  Serial.println("Relay 2 ON");
  digitalWrite(RELAY2, LOW);   // ON
  delay(1000);
  digitalWrite(RELAY2, HIGH);  // OFF
  delay(500);
  
  Serial.println("Relay 3 ON");
  digitalWrite(RELAY3, LOW);   // ON
  delay(1000);
  digitalWrite(RELAY3, HIGH);  // OFF
  delay(500);
  
  Serial.println("Relay 4 ON");
  digitalWrite(RELAY4, LOW);   // ON
  delay(1000);
  digitalWrite(RELAY4, HIGH);  // OFF
  delay(500);
  
  // turn on all
  Serial.println("ALL ON");
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);
  delay(2000);
  
  // turn off all
  Serial.println("ALL OFF");
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  delay(2000);
}