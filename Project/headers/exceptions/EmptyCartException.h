#ifndef EMPTY_CART_EXCEPTION_H
#define EMPTY_CART_EXCEPTION_H

#include <exception>

class EmptyCartException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // EMPTY_CART_EXCEPTION_H
