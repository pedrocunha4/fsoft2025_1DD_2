#include "../../headers/model/ClientOrder.h"
#include <iostream>
#include <iomanip>

ClientOrder::ClientOrder(const std::vector<std::pair<Product, int>>& items, float total)
    : items(items), total(total) {}

void ClientOrder::show() const {
    std::cout << "\n--- Order ---\n";
    for (const auto& item : items) {
        std::cout << "Product: " << item.first.getName()
                  << " | Quantity: " << item.second
                  << " | Price: " << std::fixed << std::setprecision(2)
                  << item.first.getPriceClient() << " EUR\n";
    }
    std::cout << "Total: " << std::fixed << std::setprecision(2)
              << total << " EUR\n";
    std::cout << "-----------------------------\n";
}

float ClientOrder::getTotal() const {
    return total;
}

const std::vector<std::pair<Product, int>>& ClientOrder::getItems() const {
    return items;
}
