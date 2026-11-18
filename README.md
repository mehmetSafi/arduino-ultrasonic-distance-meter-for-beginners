# Arduino Ultrasonic Distance Meter

Measures distance with an HC-SR04 sensor and turns on an LED when an object is closer than 20 cm.

## Components
- Arduino Uno
- HC-SR04 ultrasonic sensor
- LED + 220Ω resistor

## Wiring
| HC-SR04 | Arduino |
|---------|---------|
| VCC     | 5V      |
| GND     | GND     |
| Trig    | D9      |
| Echo    | D10     |

## How it works
The sensor sends a pulse and measures the echo time. Distance = time × 0.0343 / 2.
