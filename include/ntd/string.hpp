#ifndef __NTD_STRING_HPP__
#define __NTD_STRING_HPP__

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace ntd {

    std::string replace(const std::string string, const std::string from, const std::string to) {
        auto new_string = std::string{string};

        if(string.empty()) {
            return std::string{""};
        }

        auto start_position = size_t{0};

        while((start_position = new_string.find(from, start_position)) != std::string::npos) {
            new_string.replace(start_position, from.length(), to);

            start_position += to.length();
        }

        return new_string;
    }

    std::vector<std::string> split(const std::string string, const char delimeter) {
        std::vector<std::string> strings;

        std::istringstream f(string);
        std::string s;

        while(std::getline(f, s, delimeter)) {
            strings.push_back(s);
        }

        return strings;
    }

    std::string to_lower(const std::string str) {
        auto nstr = std::string{str};

        std::transform(nstr.begin(), nstr.end(), nstr.begin(), ::tolower);

        return nstr;
    }

    std::string to_upper(const std::string str) {
        auto nstr = std::string{str};

        std::transform(nstr.begin(), nstr.end(), nstr.begin(), ::toupper);

        return nstr;
    }

    inline std::string ltrim(const std::string str) {
        auto s = std::string{str};

        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));

        return s;
    }


    inline std::string rtrim(const std::string str) {
        auto s = std::string{str};

        s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());

        return s;
    }

    inline std::string trim(const std::string str) {
        auto s = std::string{str};

        return ltrim(rtrim(s));
    }
}

#endif
