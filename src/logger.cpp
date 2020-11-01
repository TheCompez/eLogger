#include "logger.hpp"
#include "core.hpp"

namespace eLogger {

Logger::Logger() {}

Logger::~Logger() {}

void Logger::echo(const unsigned int counter,
                  const time_t occurTime,
                  const unsigned int line,
                  const std::string &function,
                  const std::string &file,
                  const std::string &message,
                  const int type)
{
    std::thread::id threadId = std::this_thread::get_id();
    std::stringstream strThreadId;
    strThreadId << threadId;

    std::mutex           _mutex;
    std::string          typeStr         = STR_NULL;
    std::ostream&        streamInStyle   = std::cout;
    std::string          beginStyle      = STR_NULL;
    std::string          endStyle        = STR_NULL;

    switch (type) {
    case LoggerType::Default:
        typeStr     =  "Default";
        streamInStyle       << NativeTerminal::Default;
        beginStyle  = "\033[0;90m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Info:
        typeStr =  "Info" ;
        streamInStyle       << NativeTerminal::Info;
        beginStyle  = "\033[0;37m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Warning:
        typeStr =  "Warning" ;
        streamInStyle       << NativeTerminal::Warning;
        beginStyle  = "\033[0;33m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Critical:
        typeStr =  "Critical" ;
        streamInStyle       << NativeTerminal::Critical;
        beginStyle  = "\033[0;31m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Failed:
        typeStr =  "Failed" ;
        streamInStyle       << NativeTerminal::Error;
        beginStyle  = "\033[1;91m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Success:
        typeStr =  "Success" ;
        streamInStyle       << NativeTerminal::Success;
        beginStyle  = "\033[0;32m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Done:
        typeStr =  "Done" ;
        streamInStyle       << NativeTerminal::Done;
        beginStyle  = "\033[1;92m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::Paused:
        typeStr =  "Paused" ;
        streamInStyle       << NativeTerminal::Paused;
        beginStyle  = "\033[1;96m";
        endStyle    = "\033[0m";
        break;
    case LoggerType::InProgress:
        typeStr =  "InProgress" ;
        streamInStyle       << NativeTerminal::InProgress;
        beginStyle  = "\033[1;93m";
        endStyle    = "\033[0m";
        break;
    }

    if(LoggerModel == Mode::User) {

        streamInStyle << " => Log Id : [" << counter
                      << "] : ["  << typeStr << "] "
                      << message << " { DateTime: "
                      << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                      << NativeTerminal::Reset << newline;

        std::lock_guard<std::mutex> lock(_mutex);

    } else if(LoggerModel == Mode::Developer) {

        streamInStyle << " => Log Id : [" << counter  << "]"
                      << "[ Line : "  << line << "] "
                      << "[ Function : "  << function << "] "
                      << "[ Thread Id : "  << strThreadId.str() << "] "
                      << "[ File : "  << file << "] "
                      << "] : ["    << typeStr << "] "
                      << message    << " { DateTime: "
                      << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                      << NativeTerminal::Reset << newline;

        std::lock_guard<std::mutex> lock(_mutex);

    } else if(LoggerModel == Mode::DataMining) {

        streamInStyle << " => Log Id : [" << counter  << "]"
                      << "[ Line : "  << line << "] "
                      << "[ Function : "  << function << "] "
                      << "[ Thread Id : "  << strThreadId.str() << "] "
                      << "[ File : "  << file << "] "
                      << "] : ["    << typeStr << "] "
                      << message    << " { DateTime: "
                      << std::put_time(localtime(&occurTime), "%Y/%m/%d %H:%M:%S") << " }"
                      << NativeTerminal::Reset << newline;
        std::lock_guard<std::mutex> lock(_mutex);
    }
}

}
