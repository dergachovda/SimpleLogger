# SimpleLogger

SimpleLogger is a lightweight logging library for Arduino, providing various log levels and simple message formatting.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
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

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) for details.
