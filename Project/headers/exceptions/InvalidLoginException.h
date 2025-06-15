#ifndef INVALID_LOGIN_EXCEPTION_H
#define INVALID_LOGIN_EXCEPTION_H

#include <exception>

class InvalidLoginException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // INVALID_LOGIN_EXCEPTION_H
