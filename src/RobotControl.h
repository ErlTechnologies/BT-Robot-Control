#ifndef BTRobotControl_h
#define BTRobotControl_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class BTRobotControl {
  public:
    BTRobotControl(uint8_t rxPin, uint8_t txPin);
    void begin(long baudRate);
    void handleBluetooth();
  private:
    SoftwareSerial mySerial;
    char data;
    void forward();
    void backward();
    void left();
    void right();
    void stoprobot();
};

