#ifndef UTIL_COMMON_COLOR_H_
#define UTIL_COMMON_COLOR_H_

#include <string>
namespace util::common {

enum Color : int {
    FG_RED = 31,
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_BLUE = 34,
    FG_DEFAULT = 39,
    BG_BLACK = 40,
    BG_RED = 41,
    BG_GREEN = 42,
    BG_BLUE = 44,
    BG_DEFAULT = 49
};

namespace color {

inline std::string colorStr(Color icolor, const std::string& istr)
{
    return "\033[0;" + std::to_string(icolor) + "m" + istr + "\033[0m";
}
inline std::string colorStr(Color icolor, const std::string&& istr)
{
	return colorStr(icolor, istr);
}

}  // namespace color
}  // namespace util::common
#endif  // UTIL_COMMON_COLOR_H_
