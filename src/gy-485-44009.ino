#include <SoftwareSerial.h>

#define RX_PIN 10 // Define the RX pin for SoftwareSerial
#define TX_PIN 11 // Define the TX pin for SoftwareSerial

SoftwareSerial rs485Serial(RX_PIN, TX_PIN);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the RS-485 serial communication
  rs485Serial.begin(9600);

  // Give some time for the sensor to initialize
  delay(2000);

  // Example command to query the output (0xA5 0x09 0xAE)
  uint8_t queryCommand[] = {0xA5, 0x09, 0xAE};

  // Send the query command to the sensor
  rs485Serial.write(queryCommand, sizeof(queryCommand));
}

void loop() {
  // Wait for the sensor to respond
  delay(100); // Adjust this delay based on the sensor's response time

  // Check if data is available from the sensor
  if (rs485Serial.available() >= 9) {
    uint8_t frame[9];

    // Read the incoming data
    for (int i = 0; i < 9; i++) {
      frame[i] = rs485Serial.read();
    }

    // Verify frame header and checksum
    if (frame[0] == 0x5A && frame[1] == 0x5A && frame[3] == 0x04) {
      uint8_t checksum = frame[0] + frame[1] + frame[2] + frame[3] + frame[4] + frame[5] + frame[6] + frame[7];
      if (checksum == frame[8]) {
        // Calculate the lux value
        uint32_t lux = (frame[4] << 24) | (frame[5] << 16) | (frame[6] << 8) | frame[7];
        float luxValue = lux / 100.0;

        // Print the received data and calculated lux value
        Serial.print("Received data: ");
        for (int i = 0; i < 9; i++) {
          Serial.print(frame[i], HEX);
          Serial.print(" ");
        }
        Serial.println();

        Serial.print("Calculated lux value: ");
        Serial.println(luxValue);
      } else {
        Serial.println("Checksum error");
      }
    } else {
      Serial.println("Invalid frame header or data volume");
    }
  }

  // Add a delay before the next request to avoid overwhelming the sensor
  delay(1000);

  // Send the query command to the sensor again
  uint8_t queryCommand[] = {0xA5, 0x09, 0xAE};
  rs485Serial.write(queryCommand, sizeof(queryCommand));
}
