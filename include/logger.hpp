#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "common.hpp"

#include <ctime>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <ostream>
#include <iomanip>

namespace eLogger {

/*!
 * \brief The LoggerType enum
 */
enum LoggerType
{
    Default,
    Info,
    Warning,
    Critical,
    Failed,
    Success,
    Done,
    Paused,
    InProgress
};

enum class Mode {
    User,
    Developer,
    DataMining
};


#define Log(message, type)                                             \
Logger::echo(_elogger_counter_,                                        \
std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()),\
_elogger_line_,                                                        \
_elogger_function_,                                                    \
_elogger_file_,                                                        \
message, type)

class Logger;
/*!
 * \brief The Logger class
 */
class ELOGGER_EXPORT Logger
{
public:
    Logger();
    ~Logger();

    inline static Mode LoggerModel = Mode::User;

    static void echo(const unsigned int &counter,
                     const time_t  &occurTime,
                     const unsigned int &line,
                     std::string_view function,
                     std::string_view file,
                     std::string_view message,
                     const int &type);

};

}

#endif // LOGGER_HPP
