#ifndef __NTD_STRING_HPP__
#define __NTD_STRING_HPP__

#include <string>
#include <vector>
#include <sstream>

namespace ntd {
    std::string replace(const std::string, const std::string, const std::string);
    std::vector<std::string> split(const std::string, const char);
}

#endif