#include "../../headers/model/StepUp.h"

#include <stdexcept>

StepUp::StepUp() {
    // vazio por agora
}

std::vector<Product>& StepUp::getProducts() {
    return products;
}

std::vector<Client>& StepUp::getClients() {
    return clients;
}

Manager& StepUp::getManager() {
    return manager;
}

std::vector<Supplier>& StepUp::getSuppliers() {
    return suppliers;
}

std::vector<ClientOrder>& StepUp::getClientOrders() {
    return clientOrders;
}

std::vector<SupplierOrder>& StepUp::getSupplierOrders() {
    return supplierOrders;
}

Product& StepUp::findProductById(int id) {
    for (auto& p : products) {
        if (p.getId() == id)
            return p;
    }
    throw std::runtime_error("Product not found.");
}

void StepUp::setManager(const Manager& manager) {
    this->manager = manager;
}


