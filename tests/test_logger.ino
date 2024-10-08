#include <SimpleLogger.h>
#include <ArduinoUnit.h>

SimpleLogger Log;

test(logInitialization) {
    Serial.begin(115200);
    Log.init(Serial);
    Log.setLogLevel(INFO);
    Log.log("Logger initialized.", INFO);
    assertTrue(true);
}

test(logMessage) {
    Log.log("This is a test log message.", INFO);
    assertTrue(true);  // Check output manually
}

void setup() {
    Test::begin();
}

void loop() {
    Test::run();
}
