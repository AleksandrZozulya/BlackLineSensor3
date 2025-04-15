#include "BlackLineSensor3.h"

BlackLineSensor3::BlackLineSensor3(int pin1, int pin2, int pin3) : S0(pin1), S1(pin1), S2(pin2)
{
}

void BlackLineSensor3::begin(int level)
{
    this->level = level;
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
}

bool BlackLineSensor3::compareLineValues(bool s0, bool s1, bool s2, bool s3, bool s4, bool s5, bool s6, bool s7) {
    return sensors[0] == s0 &&
           sensors[1] == s1 &&
           sensors[2] == s2 &&
           sensors[3] == s3 &&
           sensors[4] == s4 &&
           sensors[5] == s5 &&
           sensors[6] == s6 &&
           sensors[7] == s7;
  }

  void BlackLineSensor3::updateSensors() {
    for (uint8_t i = 0; i < 8; i++) {
      sensors[i] = readLineSensorBool(i);
    }
  }
