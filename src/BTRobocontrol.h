#ifndef BTRobocontrol_h
#define BTRobocontrol_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class BTRobocontrol {
  public:
    BTRobocontrol(uint8_t rxPin, uint8_t txPin);
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

