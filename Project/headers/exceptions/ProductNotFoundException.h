#ifndef PRODUCT_NOT_FOUND_EXCEPTION_H
#define PRODUCT_NOT_FOUND_EXCEPTION_H

#include <exception>

class ProductNotFoundException : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif // PRODUCT_NOT_FOUND_EXCEPTION_H
