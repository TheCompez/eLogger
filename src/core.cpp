#include "core.hpp"

namespace eLogger {

Core::Core()
{
    //ToDo...
}

Core::~Core()
{
    //ToDo...
}

NativeTerminal::NativeTerminal()
{

}

NativeTerminal::~NativeTerminal()
{

}

void NativeTerminal::setColor(const NativeTerminal::ColorType &color)
{

#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
#else
    //  std::string beginStyle  = STR_NULL;
    //  std::string endStyle    = STR_NULL;
    //  beginStyle  = "\033[0;90m";
    //  endStyle    = "\033[0m";
    //ToDo...
#endif
}

void NativeTerminal::resetColor()
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    //ToDo...
#endif
}

std::ostream &NativeTerminal::Default(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(7));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Info(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::GRAY));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Warning(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::YELLOW));
#else
    stream << "\033[0;33m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Critical(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::LIGHTRED));
#else
    stream << "\033[0;31m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Error(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::RED));
#else
    stream << "\033[0;91m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Success(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::GREEN));
#else
    stream << "\033[0;32m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Done(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::LIGHTGREEN));
#else
    stream << "\033[0;92m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Paused(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::CYAN));
#else
    stream << "\033[0;96m";
#endif
    return stream;
}

std::ostream &NativeTerminal::InProgress(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::BROWN));
#else
    stream << "\033[0;93m";
#endif
    return stream;
}


std::ostream &NativeTerminal::Reset(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::LIGHTGRAY));
#else
    stream << "\033[0;37m";
#endif
    return stream;
}

std::ostream &NativeTerminal::Primary(std::ostream &stream)
{
#ifdef __ELOGGER_WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(FOREGROUND_COLORS::BROWN));
#else
    stream << "\033[0;35m";
#endif
    return stream;
}


}
