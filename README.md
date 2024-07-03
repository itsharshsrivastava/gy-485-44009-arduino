# Arduino Sketch for Gy-485-44009 Sensor

This Arduino sketch demonstrates how to communicate with an Gy-485-44009 sensor module using SoftwareSerial. The example provided reads data from the sensor and calculates the lux value based on the received data frame.

## Dependencies

- Arduino IDE (tested with version 2.3.2)
- SoftwareSerial library (included with Arduino IDE)

## Hardware Requirements

- **Arduino Board**: Any Arduino board compatible with the Arduino IDE, such as Arduino Uno.
- **RS-485 Module**: A module capable of RS-485 serial communication. This module typically has RX (Receiver), TX (Transmitter), GND, and VCC pins.
- **Gy-485-44009 sensor**: High Precision RS485 Illuminance Light Intensity Brightness Sensor Module.

## Connections

# Between Arduino Uno and 485 to TTL converter
    Arduino Uno                485 to TTL converter
    VCC    --------------------->    VCC
    GND    --------------------->    GND
    RX     --------------------->    RXD
    TX     --------------------->    TXD

# Between Gy-485-44009 and 485 to TTL converter
    Gy-485-44009                   485 to TTL converter
        A+     --------------------->    A+
        B-     --------------------->    B-
# Between Arduino Uno and Gy-485-44009
    Arduino Uno                  Gy-485-44009
    3.3 V  --------------------->    VCC
    GND    --------------------->    GND
    
## Installation

1. **Install Arduino IDE**: Download and install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).

2. **Clone Repository**: Clone this repository to your local machine using the following command in your terminal or command prompt:

   ```bash
   git clone https://github.com/itsharshsrivastava/gy-485-44009-arduino.git
