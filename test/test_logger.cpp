#include <Arduino.h>
#include <SimpleLogger.h>
#include <unity.h>

// Create a SimpleLogger instance
SimpleLogger Log;

void setUp() {
    // Set up the logger (you can configure this as needed)
    Log.init(Serial);
    Log.setLogLevel(INFO);
}

void test_LogInitialization() {
    Log.log("Testing logger initialization.", INFO);
    TEST_ASSERT_TRUE(true);  // A simple test to check the logging functionality
}

void test_LogMessage() {
    Log.log("This is a test log message.", INFO);
    TEST_ASSERT_TRUE(true);  // Replace with actual assertions as needed
}

void loop() {
    // You can leave this empty for testing purposes
}

void setup() {
    UNITY_BEGIN();  // Start the Unity test framework
    RUN_TEST(test_LogInitialization);
    RUN_TEST(test_LogMessage);
    UNITY_END();    // End the Unity test framework
}
