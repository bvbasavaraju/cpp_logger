#include <iostream>

#include "status_t.h"
#include "error_codes_t.h"
#include "smart_pointer_t.h"
#include "logger_wrapper_t.h"

using namespace std;
using namespace cpplogger;

class Logger_t : public ICppLogger_t
{
  private:
    void LogLevel(ICppLogger_t::LogLevel_t level)
    {
      switch (level)
      {
        case ICppLogger_t::LOG_LEVEL_INFO:
          std::cout << "Information: ";
          break;

        case ICppLogger_t::LOG_LEVEL_WARNING:
          std::cout << "Warning: ";
          break;

        case ICppLogger_t::LOG_LEVEL_TRACE:
          std::cout << "Trace: ";
          break;

        case ICppLogger_t::LOG_LEVEL_ERROR:
          std::cout << "Error: ";
          break;

        case ICppLogger_t::LOG_LEVEL_CRITICAL:
          std::cout << "Critical: ";
          break;
      }
    }

    void LogData_(
      ICppLogger_t::LogLevel_t level,
      uint32_t lineNumber, 
      const char* function, 
      const char* filename)
    {
      LogLevel(level);

      if(function != 0)
      {
        std::cout << function;
      }

      if(lineNumber > 0)
      {
        std::cout << "[#" << std::dec << lineNumber << "] - ";
      }

      if(filename != 0)
      {
        std::cout << filename << " - ";
      }
    }

    void LogData_(
      ICppLogger_t::LogLevel_t level, 
      int64_t errorCode,
      uint32_t lineNumber, 
      const char* function, 
      const char* filename,
      const char* errorMessage)
    {
      LogData_(level, lineNumber, function, filename);

      std::cout << "Resulted in error: [ 0x" << std::hex << errorCode << " ]" << std::endl;
      if(errorMessage != 0)
      {
        std::cout << "LogMessage: " << errorMessage << std::endl;
      }
    }

  public:
    Logger_t()
    {}

    ~Logger_t()
    {}

    virtual void LogData(
      ICppLogger_t::LogLevel_t level,
      int64_t errorCode)
    {
      LogData_(level, errorCode, 0, 0, 0, 0);
    }

    virtual void LogData(
      ICppLogger_t::LogLevel_t level,
      int64_t errorCode,
      const char* errorMessage)
    {
      LogData_(level, errorCode, 0, 0, 0, errorMessage);
    }

    virtual void LogData(
      ICppLogger_t::LogLevel_t level, 
      int64_t errorCode,
      uint32_t lineNumber, 
      const char* filename)
    {
      LogData_(level, errorCode, lineNumber, 0, filename, 0);
    }

    virtual void LogData(
        ICppLogger_t::LogLevel_t level, 
        int64_t errorCode,
        uint32_t lineNumber, 
        const char* filename,
        const char* errorMessage)
    {
      LogData_(level, errorCode, lineNumber, 0, filename, errorMessage);
    }

    virtual void LogData(
      ICppLogger_t::LogLevel_t level, 
      int64_t errorCode,
      uint32_t lineNumber, 
      const char* function, 
      const char* filename,
      const char* errorMessage)
    {
      LogData_(level, errorCode, lineNumber, function, filename, errorMessage);
    }

    virtual void LogData(
        LogLevel_t level,
        uint32_t lineNumber,
        const char* function,
        const char* filename,
        const char* format,
        va_list& args)
    {
      LogData_(level, lineNumber, function, filename);
      vprintf(format, args);
      std::cout << std::endl;
    }
};

int main()
{
  {
    SmartPtr_t<Logger_t> logger_ = new Logger_t();
    if(logger_.IsNull())
    {
      return -1;
    }

    SmartPtr_t<LoggerWrapper_t> logWrapper;
    Status_t status = LoggerWrapper_t::Create(logger_, logWrapper);
    if(status.IsBad() || logWrapper.IsNull())
    {
      return -1;
    }

    CPP_LOG_ERROR(GOOD);
    CPP_LOG_ERROR(BAD_NOTHING_TO_DO);
    CPP_LOG_ERROR_MSG("This is the test to see if string based error message works");
    CPP_LOG_ERROR_CODE_AND_MSG(BAD_NOTHING_TO_DO, "This is the test to see if string based error message works");
    CPP_LOG_ERROR_DATA("%s %d %f", "Hi there", 123, 12.1234);
  }

  return 0;
}