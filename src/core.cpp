#include "core.hpp"
#include <sstream>

E_LOGGER_NAMESPACE_BEGIN(eLogger)

Core::Core()
{
    //TODO...
}

Core::~Core()
{
    //TODO...
}

std::string Core::getStandard()
{
    std::stringstream langStandard;
    langStandard << __cplusplus;
    std::string res = langStandard.str();
    if (!res.empty()) {
        res.erase(res.size() - 2); //Get only year number from ISO/IEC!
    }
    return res;
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

void Core::init()
{
    std::ostream&    streamInStyle   = std::cout;
    streamInStyle << "eLogger " << __e_full_version << " - " << "compiled on " << __e_compiled_date << __e_newline;
    streamInStyle << "Release mode: " << __e_release_mode << " - " << __e_release_mode_number << __e_newline;
    streamInStyle << __e_bold << "Host machine init: " << __e_reset << __e_newline;
    streamInStyle << "Operation System: "  << __e_platform_os << __e_newline;
    streamInStyle << "Language Standard: " << __e_under_score << "ISO/IEC 14882:" << getStandard() << __e_reset << __e_newline;
    streamInStyle << "Compiler Type: " << __e_compiler << ":" << __e_compiler_ver << __e_newline;
}

E_LOGGER_NAMESPACE_END
