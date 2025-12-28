#ifndef RESULT_H
#define RESULT_H

#include <string>


class Result {
private:
    int result{};
    std::wstring resultMsg;

public:
    Result(int result, const std::wstring &message);

    const int getResult() const;
    const std::wstring getMessage() const;

    bool operator==(const Result &other) const;

    bool isOK() const;
    bool isNOK() const;

    static const Result OK();
    static const Result OK(const std::wstring &message);

    static const Result NOK(const std::wstring &message);
    static const Result NOK(int number, const std::wstring &message);
};
#endif //RESULT_H