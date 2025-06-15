#ifndef ORDER_NOT_FOUND_EXCEPTION_H
#define ORDER_NOT_FOUND_EXCEPTION_H

#include <exception>

class OrderNotFoundException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // ORDER_NOT_FOUND_EXCEPTION_H
