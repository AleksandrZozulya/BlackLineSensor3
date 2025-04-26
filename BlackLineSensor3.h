#ifndef BlackLineSensor3_h
#define BlackLineSensor3_h
#include "Arduino.h"

class BlackLineSensor3
{
public:
    BlackLineSensor3(int pin1, int pin2, int pin3);
    void begin(int level, int numOfSensors);
    uint8_t readLineSensor(uint8_t channel);
    bool readLineSensorBool(uint8_t channel);
    bool compareLine8Values(bool s0, bool s1, bool s2, bool s3, bool s4, bool s5, bool s6, bool s7);
    bool compareLine6Values(bool s0, bool s1, bool s2, bool s3, bool s4, bool s5);
    void updateSensors();
    
private:
    const int S0;
    const int S1;
    const int S2;
    int level;
    int numOfSensors;
    bool sensors[8];
};

#endif
