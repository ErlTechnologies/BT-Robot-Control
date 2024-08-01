#ifndef VOICE_CONTROLLED_ROBOT_H
#define VOICE_CONTROLLED_ROBOT_H

#include <SoftwareSerial.h>

class VoiceControlledRobot {
public:
    VoiceControlledRobot(int rxPin, int txPin, int in1, int in2, int in3, int in4);
    void begin(long baudRate);
    void update();
    
private:
    void forward();
    void reverse();
    void left();
    void right();
    void stopRobot();
    
    SoftwareSerial MySerial;
    int IN1, IN2, IN3, IN4;
};

#endif // VOICE_CONTROLLED_ROBOT_H
