# esp32-debounced-led-control

An embedded C++ simulation built in Wokwi demonstrating digital output control, internal pull-up inputs, and software debouncing on an ESP32 microcontroller.

## Hardware & Pinout

| Component | ESP32 Pin | Configuration |
| :--- | :--- | :--- |
| **LED 1** | GPIO 4 | Series 220 Ω resistor to GND |
| **LED 2** | GPIO 23 | Series 220 Ω resistor to GND |
| **Pushbutton** | GPIO 2 | Wired to GND (Uses internal `INPUT_PULLUP`) |

## Technical Features

* **Non-Blocking Debouncing:** Employs a 50 ms time threshold with `millis()` to eliminate mechanical switch contact chatter without interrupting execution.
* **Minimal Hardware Footprint:** Configures GPIO 4 with `INPUT_PULLUP` to remove the need for external pull-up resistors.

## Engineering Challenges & Fixes

| Issue | Root Cause | Solution |
| :--- | :--- | :--- |
| **No output on GPIO 35** | Pins 34–39 on the ESP32 are input-only (GPI) and lack output drivers. | Remapped the output driver to **GPIO 22**. |
| **Pin Mismatch Errors** | `setup()` initialized pins 2 and 4, while `loop()` targeted pins 23 and 35. | Consolidated all pin numbers into global `const int` constants. |
| **Button Signal Chatter** | Physical switch bounce registered rapid false toggle events. | Implemented non-blocking timing logic to validate state stability. |

## How to Run

1. Open the project link on [Wokwi Simulation](https://wokwi.com).
2. Click **Start Simulation** (Play button).
3. Press and hold the pushbutton to illuminate both LEDs.
