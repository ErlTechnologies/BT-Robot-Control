#include <SoftwareSerial.h>

#define IN1 5
#define IN2 6
#define IN3 11
#define IN4 10

SoftwareSerial MySerial(8, 9); // RX, TX

void setup() {
  Serial.begin(9600); // Initialize serial communication with the computer
  MySerial.begin(9600); // Initialize serial communication with the Bluetooth module

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("Voice Controlled Robot Initialized");
}

void loop() {
  if (MySerial.available()) {
    String command = MySerial.readStringUntil('\n');
    command.trim();
    command.toUpperCase(); // Convert the command to uppercase for case-insensitive comparison
    
    Serial.print("Command received: ");
    Serial.println(command);

    if (command == "*FORWARD#") {
      forward();
    } else if (command == "*REVERSE#") {
      reverse();
    } else if (command == "*LEFT#") {
      left();
    } else if (command == "*RIGHT#") {
      right();
    } else if (command == "*STOP#") {
      stopRobot();
    } else {
      Serial.println("Invalid Command");
    }
  }
}

void forward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Moving Forward");
}

void reverse() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Moving Reverse");
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Turning Left");
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Turning Right");
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopping");
}
