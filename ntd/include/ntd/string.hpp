#ifndef __NTD_STRING_HPP__
#define __NTD_STRING_HPP__

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace ntd {

    /**
        Replaces all occurrences of a specified substring with another string.

        <b>Example</b>

        <pre>
        auto text = ntd::replace("Java is awesome", "Java", "C++14"); // text = "C++14 is awesome"
        </pre>

        @param string The string where you want to replace things from
        @param from The substring you want to replace
        @param to The string which you want to insert instead of the "from" string mentioned above.

        @return Returns the first argument with all occurences of the specified "from" substring replaced with "to".
    */
    std::string replace(const std::string, const std::string, const std::string);

    /**
        Splits a string by a specified delimeter

        <b>Example</b>

        <pre>
        auto words = ntd::replace("Lorem ipsum dolor sit amet", ' '); // words = {"Lorem", "ipsum", ...}
        </pre>

        @param string Your base string
        @param delimeter The delimiter with which you'll split the string

        @return Returns a std::vector<std::string> which contains several substrings based on your delimeter.
    */
    std::vector<std::string> split(const std::string, const char);

    std::string to_lower(const std::string);
    std::string to_upper(const std::string);
}

#endif
