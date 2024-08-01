#include <SoftwareSerial.h>

SoftwareSerial MySerial(8, 9); 
const int relayFan = 7; 
const int relayLight = 4; 

void setup() {
  Serial.begin(9600); 
  MySerial.begin(9600); 

  pinMode(relayFan, OUTPUT); 
  pinMode(relayLight, OUTPUT); 

  digitalWrite(relayFan, LOW);
  digitalWrite(relayLight, LOW); 

  Serial.println("Voice Controlled Home Automation System"); 
}

void loop() {
  if (MySerial.available()) { 
    String command = MySerial.readStringUntil('\n'); 
    command.trim(); 

    
    command.toUpperCase();
    
    Serial.print("Command received: ");
    Serial.println(command); 

    
    if (command == "FAN ON") {
      digitalWrite(relayFan, HIGH); 
      Serial.println("Fan turned ON");
    } else if (command == "FAN OFF") {
      digitalWrite(relayFan, LOW); 
      Serial.println("Fan turned OFF");
    } else if (command == "LIGHT ON") {
      digitalWrite(relayLight, HIGH); 
      Serial.println("Light turned ON");
    } else if (command == "LIGHT OFF") {
      digitalWrite(relayLight, LOW); 
      Serial.println("Light turned OFF");
    } else {
      Serial.println("Invalid Command"); 
    }
  }
}
