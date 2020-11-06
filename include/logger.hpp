#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "common.hpp"

#include <ctime>
#include <iostream>
#include <string_view>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <ostream>
#include <iomanip>

E_LOGGER_NAMESPACE_BEGIN(eLogger)

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
Logger::echo(__e_compiler_counter,                                        \
std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()),\
__e_compiler_line,                                                        \
__e_compiler_function,                                                    \
__e_compiler_file,                                                        \
message, type)

class Logger;
/*!
 * \brief The Logger class
 */
class __e_logger_export Logger
{
public:
    Logger();
    ~Logger();

    inline static Mode LoggerModel = Mode::User;

    [[maybe_unused]] static void echo(const unsigned int counter,
                                      const time_t  occurTime,
                                      const unsigned int line,
                                      std::string_view function,
                                      std::string_view file,
                                      std::string_view message,
                                      const int type);

};

E_LOGGER_BRACE_END

#endif // LOGGER_HPP
