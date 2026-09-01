# Arduino-Anti-Drunk-Driving-System
This prototype detects a driver's presence and monitors their breath for alcohol. If the driver is sober, an indicator light remains on to show the engine is unlocked. If alcohol is detected, the system triggers an alarm and turns the light off, simulating an engine kill-switch to prevent the car from starting.

## Circuit Connections

### Power Supply (Breadboard Setup)
To make wiring easier, set up a common power line on your breadboard:
* Connect the **5V pin** on the Arduino to the **Positive (+)** rail on the breadboard.
* Connect the **GND pin** on the Arduino to the **Negative (-)** rail on the breadboard.

### MQ-3 Alcohol Sensor
* **VCC:** Connect to Breadboard Positive (+)
* **GND:** Connect to Breadboard Negative (-)
* **A0 (Analog Out):** Connect to **Arduino Pin A0**

### HC-SR04 Ultrasonic Sensor
* **VCC:** Connect to Breadboard Positive (+)
* **GND:** Connect to Breadboard Negative (-)
* **TRIG:** Connect to **Arduino Pin 9**
* **ECHO:** Connect to **Arduino Pin 10**

### Buzzer
* **Positive (Longer leg / Red wire):** Connect to **Arduino Pin 11**
* **Negative (Shorter leg / Black wire):** Connect to Breadboard Negative (-)

### LED (Engine Indicator)
* **Positive (Longer leg / Anode):** Connect to **Arduino Pin 2**
* **Negative (Shorter leg / Cathode):** Connect to one end of a **220Ω resistor**. Connect the other end of the resistor to Breadboard Negative (-)

> **Note:** Always use a 220Ω or 330Ω resistor with the LED to prevent it from burning out.
