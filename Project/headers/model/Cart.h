#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>

class Cart {
private:
    std::vector<std::pair<Product, int>> items;

public:
    void addProduct(const Product& product, int quantity);
    void showCart() const;
    void removeProductById(int productId);
    float getTotal() const;
    bool isEmpty() const;
    void clear();
};

#endif // CART_H
