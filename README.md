# SimpleLogger

SimpleLogger is a lightweight logging library for Arduino, providing various log levels and simple message formatting.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Resources](#resources)
- [License](#license)

## Installation

To include the `SimpleLogger` library in your PlatformIO project, follow these steps:

1. **Open your PlatformIO project**.

2. **Edit the `platformio.ini` file**: Add `SimpleLogger` as a dependency under the `[env]` section. For example:

   ```ini
   [env:your_board]
   platform = atmelavr
   board = uno  ; Change this to your specific board
   framework = arduino

   lib_deps =
       SimpleLogger
   ```

3. **Install the Library**: PlatformIO will automatically install the library when you build your project.

Alternatively, you can install the library via the Arduino Library Manager:

1. **Open the Arduino IDE**.
2. **Go to Sketch > Include Library > Manage Libraries...**.
3. **Search for "SimpleLogger"**.
4. **Click "Install"**.

## Usage

Here’s a simple example of how to use the `SimpleLogger` in your project:

```cpp
#include <Arduino.h>
#include <SimpleLogger.h>

SimpleLogger Log;

void setup() {
    Serial.begin(115200);
    Log.init(Serial);
    Log.setLogLevel(INFO);

    Log.log("Logger initialized.", INFO);
}

void loop() {
    Log.log("Running loop...", INFO);
    delay(1000);
}
```

## Examples

### Using Different Log Levels

```cpp
Log.log("This is a TRACE message", TRACE);
Log.log("This is a DEBUG message", DEBUG);
Log.log("This is an INFO message", INFO);
Log.log("This is a WARN message", WARN);
Log.log("This is an ERROR message", ERROR);
Log.log("This is a FATAL message", FATAL);
```

### Formatted Logging

```cpp
Log.logf(INFO, "Temperature is {}°C and Humidity is {}%", 23, 60);
Log.logf(DEBUG, "Motor speed: {} RPM", 1500);
```

## Resources

Links:

- [arduino-creating-library-guide](https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/)
- [PlatformIO: Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html)
- [Getting Started with Code Coverage in PlatformIO](https://piolabs.com/blog/insights/test-coverage-on-unit-testing.html)

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) for details.
