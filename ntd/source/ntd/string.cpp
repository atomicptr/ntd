#include <ntd/string.hpp>

std::string ntd::replace(const std::string string, const std::string from, const std::string to) {
    std::string new_string(string);

    if(string.empty()) {
        return std::string("");
    }

    size_t start_position = 0;

    while((start_position = new_string.find(from, start_position)) != std::string::npos) {
        new_string.replace(start_position, from.length(), to);

        start_position += to.length();
    }

    return new_string;
}

std::vector<std::string> ntd::split(const std::string string, const char delimeter) {
    std::vector<std::string> strings;

    std::istringstream f(string);
    std::string s;

    while(std::getline(f, s, delimeter)) {
        strings.push_back(s);
    }

    return strings;
}

std::string ntd::to_lower(const std::string str) {
    auto nstr = std::string{str};

    std::transform(nstr.begin(), nstr.end(), nstr.begin(), ::tolower);

    return nstr;
}

std::string ntd::to_upper(const std::string str) {
    auto nstr = std::string{str};

    std::transform(nstr.begin(), nstr.end(), nstr.begin(), ::toupper);

    return nstr;
}
