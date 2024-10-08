#include <SimpleLogger.h>

SimpleLogger Log;

void setup() {
  Serial.begin(115200);
  
  // Initialize the logger with the Serial output
  Log.init(Serial);
  
  // Set log level to DEBUG
  Log.setLogLevel(DEBUG);
  
  // Log messages with placeholders and arguments
  Log.logf(INFO, "Temperature is {}°C and Humidity is {}%", 23, 60);
  Log.logf(DEBUG, "Motor speed: {} RPM", 1500);
}

void loop() {
  // Additional log statements can go here
}
