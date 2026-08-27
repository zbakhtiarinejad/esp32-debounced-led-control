# ESP32 Debounced LED Controller

An embedded C++ project built in Wokwi demonstrating digital output control, internal pull-up inputs, and software debouncing on an ESP32 microcontroller.

## Hardware & Pinout

| Component | ESP32 Pin | Configuration |
| :--- | :--- | :--- |
| **LED 1** | GPIO 4 | Series 220 Ω resistor to GND |
| **LED 2** | GPIO 23 | Series 220 Ω resistor to GND |
| **Pushbutton** | GPIO 2 | Wired to GND (Uses internal `INPUT_PULLUP`) |

## Technical Features

* **Non-Blocking Debouncing:** Uses `millis()` state tracking to eliminate mechanical button chatter without blocking execution using `delay()`.
* **Internal Pull-Up Configuration:** Configures GPIO 2 with `INPUT_PULLUP` to remove external pull-up resistor requirements.

## Engineering Challenges & Fixes

| Issue | Root Cause | Solution |
| :--- | :--- | :--- |
| **Inverted / Duplicate Pin Definitions** | `LED1` and `BUTTON` variables shared GPIO 4, overriding output setup with `INPUT_PULLUP`. | Swapped and isolated variable assignments (`BUTTON` = 2, `LED1` = 4) to match actual circuit wiring. |
| **No Output on GPIO 35** | Pins 34–39 on the ESP32 are input-only (GPI) and cannot drive outputs. | Remapped output driver to a general-purpose GPIO. |
| **Button Switch Chatter** | Physical contact bouncing caused multiple false state change triggers. | Added software debouncing with a **50 ms** stabilization threshold. |
| **Compilation Syntax Error** | Missing semicolon after `digitalRead()` call blocked code build. | Corrected code syntax and enforced strict constant definitions. |

## How to Run

1. Open the project link on [Wokwi Simulation](https://wokwi.com).
2. Click **Start Simulation** (Play button).
3. Press the pushbutton to actuate both LEDs.
