#include "../../headers/model/Cart.h"
#include "../../headers/model/Product.h"
#include <iostream>
#include <iomanip>

void Cart::addProduct(const Product& product, int quantity) {
    for (auto& item : items) {
        if (item.first.getName() == product.getName()) {
            item.second += quantity;
            return;
        }
    }
    items.push_back({product, quantity});
}

void Cart::removeProductById(int productId) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->first.getId() == productId) {
            items.erase(it);
            std::cout << "Product removed from cart.\n";
            return;
        }
    }
    std::cout << "Product with the given ID not found in cart.\n";
}

void Cart::showCart() const {
    if (items.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }

    std::cout << "\n--- Cart Contents ---\n";
    float total = 0.0f;

    for (const auto& item : items) {
        const Product& p = item.first;
        std::cout << "ID: " << p.getId()
                  << " | Product: " << p.getName()
                  << " | Quantity: " << item.second
                  << " | Price: " << std::fixed << std::setprecision(2)
                  << p.getPriceClient() << " EUR\n";

        total += p.getPriceClient() * item.second;
    }

    std::cout << "------------------------\n";
    std::cout << "Total: " << std::fixed << std::setprecision(2)
              << total << " EUR\n";
}


float Cart::getTotal() const {
    float total = 0.0f;
    for (const auto& item : items) {
        total += item.first.getPriceClient() * item.second;
    }
    return total;
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::clear() {
    items.clear();  // Limpa todos os itens no carrinho
}

const std::vector<std::pair<Product, int>>& Cart::getItems() const {
    return items;
}




