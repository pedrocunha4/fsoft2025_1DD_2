#ifndef CLIENTORDER_H
#define CLIENTORDER_H

#include "Product.h"
#include <vector>

class ClientOrder {
private:
    std::vector<std::pair<Product, int>> items;
    float total;

public:
    ClientOrder(const std::vector<std::pair<Product, int>>& items, float total);

    void show() const;
    float getTotal() const;
    const std::vector<std::pair<Product, int>>& getItems() const;
};

#endif // CLIENTORDER_H
