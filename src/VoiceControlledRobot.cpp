#include "VoiceControlledRobot.h"
#include <Arduino.h>

VoiceControlledRobot::VoiceControlledRobot(int rxPin, int txPin, int in1, int in2, int in3, int in4)
    : MySerial(rxPin, txPin), IN1(in1), IN2(in2), IN3(in3), IN4(in4) {}

void VoiceControlledRobot::begin(long baudRate) {
    Serial.begin(baudRate);
    MySerial.begin(baudRate);

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

void VoiceControlledRobot::update() {
    if (MySerial.available()) {
        String command = MySerial.readStringUntil('\n');
        command.trim();
        command.toUpperCase();

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

void VoiceControlledRobot::forward() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Moving Forward");
}

void VoiceControlledRobot::reverse() {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println("Moving Reverse");
}

void VoiceControlledRobot::left() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Turning Left");
}

void VoiceControlledRobot::right() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Turning Right");
}

void VoiceControlledRobot::stopRobot() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Stopping");
}

