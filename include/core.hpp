#ifndef CORE_HPP
#define CORE_HPP

#include "common.hpp"

#include <iostream>
#include <string>
#include <string_view>

E_LOGGER_NAMESPACE_BEGIN(eLogger)

template <typename T>
/*!
 * @brief isset function checks any data values.
 * @param t
 * @return bool
 */
[[maybe_unused]] static auto isset(T t)
{
    if (const auto it = t; it != T{})
        // on success
        return true;
    else
        // on false...
        return false;
}

/*!
 * @brief The DeveloperMode is for enable or disable system debuging information.
 */
struct DeveloperMode {
    //Since C++17 inline variable
#if defined (ELOGGER_BUILD_DEBUG_MODE)
    inline static bool IsEnable = true;
#else
    inline static bool IsEnable = false;
#endif
};

/*!
 * \brief The Core class
 */
class __e_logger_export Core
{
public:
    Core();
    ~Core();

    static std::string getStandard();

    static void init();

    template<typename ... Args>
    [[maybe_unused]] std::string stringFormat(const std::string& format, Args ... args)
    {
        size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        if (size <= 0) {
            throw std::runtime_error("Error during formatting.");
        }
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }

    void startFunction(std::function<void(void)> func, unsigned int interval);
};

class NativeTerminal;
/*!
 * \brief The NativeTerminal class
 */
class __e_logger_export NativeTerminal {
public:
    NativeTerminal();
    ~NativeTerminal();

    enum class ColorType {
        BLACK,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY,
        DARKGREY,
        LIGHTBLUE,
        LIGHTGREEN,
        LIGHTCYAN,
        LIGHTRED,
        LIGHTMAGENTA,
        YELLOW,
        WHITE
    };

#ifdef __ELOGGER_WINDOWS

    /* Enum to store Foreground colors */
    enum class FOREGROUND_COLORS
    {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        CYAN = 3,
        RED = 4,
        MAGENTA = 5,
        BROWN = 6,
        LIGHTGRAY = 7,
        GRAY = 8,
        LIGHTBLUE = 9,
        LIGHTGREEN = 10,
        LIGHTCYAN = 11,
        LIGHTRED = 12,
        LIGHTMAGENTA = 13,
        YELLOW = 14,
        WHITE = 15

    };

    /*Enum to store Background colors*/
    enum class BACKGROUND_COLORS
    {
        NAVYBLUE = 16,
        GREEN = 32,
        TEAL = 48,
        MAROON = 64,
        PURPLE = 80,
        OLIVE = 96,
        SILVER = 112,
        GRAY = 128,
        BLUE = 144,
        LIME = 160,
        CYAN = 176,
        RED = 192,
        MAGENTA = 208,
        YELLOW = 224,
        WHITE = 240

    };

#endif

    [[maybe_unused]] void setColor(const ColorType &color);

    [[maybe_unused]] void resetColor();

    static std::ostream& Default    (std::ostream& stream);
    static std::ostream& Info       (std::ostream& stream);
    static std::ostream& Warning    (std::ostream& stream);
    static std::ostream& Critical   (std::ostream& stream);
    static std::ostream& Error      (std::ostream& stream);
    static std::ostream& Success    (std::ostream& stream);
    static std::ostream& Done       (std::ostream& stream);
    static std::ostream& Paused     (std::ostream& stream);
    static std::ostream& InProgress (std::ostream& stream);
    static std::ostream& Primary    (std::ostream& stream);

 /*!
 *\brief Reset will reset all configured colors.
 *\param stream
 *\return default color of console/terminal.
 */
   static std::ostream& Reset      (std::ostream& stream);

private:
    unsigned int m_color;

};


E_LOGGER_BRACE_END

#endif // API_HPP
