# BlackLineSensor3

**BlackLineSensor3** is a library for working with multiple analog line sensors through a multiplexer controlled by three select lines (S0, S1, S2) on an Arduino.

---

## Installation

1. Copy the `BlackLineSensor3.h` and `BlackLineSensor3.cpp` files into your Arduino project's libraries folder.
2. Include the library in your sketch:

```cpp
#include "BlackLineSensor3.h"
```

---

## Hardware Requirements

- Arduino board (Uno or compatible).
- Multiplexer with three select lines (S0, S1, S2).
- Analog line sensors with analog outputs.
- One analog input on Arduino (typically A0).

---

## Constructor

| Signature | Description |
|:---|:---|
| `BlackLineSensor3(int pin1, int pin2, int pin3)` | Creates a sensor object to control the multiplexer. **Note:** S0 and S1 are both assigned to `pin1`, which might be a mistake. |

**Parameters:**
- `pin1` — the pin connected to both S0 and S1 (recommended to separate them).
- `pin2` — the pin connected to S2.

---

## Methods

| Method | Description |
|:---|:---|
| `void begin(int level, int numOfSensors)` | Initializes pins and sets the detection threshold. |
| `void updateSensors()` | Updates the internal `sensors` array with the current sensor states. |
| `uint8_t readLineSensor(uint8_t channel)` | Reads the analog value from the specified sensor channel. |
| `bool readLineSensorBool(uint8_t channel)` | Reads a sensor and returns `true` if the value exceeds the threshold. |
| `bool compareLine8Values(bool s0, ..., bool s7)` | Compares the current states of 8 sensors with the given pattern. |
| `bool compareLine6Values(bool s0, ..., bool s5)` | Compares the current states of 6 sensors with the given pattern. |

---

## Example Usage

```cpp
#include "BlackLineSensor3.h"

BlackLineSensor3 lineSensor(2, 3, 4); // Example pin setup

void setup() {
  lineSensor.begin(500, 6); // Threshold 500, 6 sensors
  Serial.begin(9600);
}

void loop() {
  lineSensor.updateSensors();

  if (lineSensor.compareLine6Values(true, false, false, false, false, true)) {
    Serial.println("Line detected with the given pattern!");
  }
}
```

---

## Important Notes

- **Constructor:** In the current implementation, both `S0` and `S1` are connected to the same pin (`pin1`). Typically, these should be separate pins when using a multiplexer. Consider fixing this.
- **Sensor reading:** All sensor values are read through a single analog pin (`A0`), and switching between sensors is controlled by setting S0-S2.
- **Channel range:** Valid channels are from `0` to `numOfSensors - 1`.

---

## License

Free to use and modify for personal and educational purposes.

