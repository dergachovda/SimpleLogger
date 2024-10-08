#ifndef SIMPLE_LOGGER_H
#define SIMPLE_LOGGER_H

#include <Arduino.h>
#include <stdarg.h> // For handling variable arguments

// Enum for log levels
enum LogLevel {
  TRACE,
  DEBUG,
  INFO,
  WARN,
  ERROR,
  FATAL
};

class SimpleLogger {
  private:
    Stream* outputStream;
    LogLevel currentLogLevel;

  public:
    // Initialization method to set the output stream
    void init(Stream &stream) {
      outputStream = &stream;
      currentLogLevel = INFO; // Default log level
    }

    // Method to set the log level
    void setLogLevel(LogLevel level) {
      currentLogLevel = level;
    }

    // Method to log a message with a log level
    void log(const String &msg, LogLevel level) {
      if (outputStream && level >= currentLogLevel) {
        outputStream->println(getLevelString(level) + ": " + msg);
      }
    }

    // Formatted logging method using {} placeholders and variable arguments
    void logf(LogLevel level, const String &format, ...) {
      if (outputStream && level >= currentLogLevel) {
        va_list args;
        va_start(args, format);

        // Buffer for the final message
        String formattedMessage = formatMessage(format, args);
        va_end(args);

        // Output the formatted message
        outputStream->println(getLevelString(level) + ": " + formattedMessage);
      }
    }

  private:
    // Helper method to format the message with {} placeholders
    String formatMessage(const String &format, va_list args) {
      String formatted = format;
      int argIndex = 0;

      // Look for all occurrences of "{}" and replace them with arguments
      while (formatted.indexOf("{}") != -1) {
        int startIndex = formatted.indexOf("{}");

        // Use va_arg to fetch the next argument (assuming int for simplicity)
        String arg = String(va_arg(args, int));

        // Replace the first occurrence of "{}" with the argument
        formatted = formatted.substring(0, startIndex) + arg + formatted.substring(startIndex + 2);
        
        argIndex++;
      }
      return formatted;
    }

    // Helper method to convert log level to string
    String getLevelString(LogLevel level) {
      switch (level) {
        case TRACE: return "TRACE";
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case FATAL: return "FATAL";
        default: return "UNKNOWN";
      }
    }
};

#endif
