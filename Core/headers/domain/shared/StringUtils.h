#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>

#include <string>

class StringUtils {
public:
    static std::wstring toUpperCase(const std::wstring &value);
    static std::wstring toLowerCase(const std::wstring &value);

    static std::wstring leftTrim(const std::wstring &value);
    static std::wstring rightTrim(const std::wstring &value);
    static std::wstring trim(const std::wstring &value);

    static bool ensureNotNullOrEmpty(const std::wstring &value);
    static bool ensureNotNullOrEmpty(const std::wstring &value, int minLength);

    static std::string toString(const std::wstring &value);
    static std::wstring toWString(const std::string &value);
};

#endif //STRINGUTILS_H