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

std::vector<Supplier>& StepUp::getSuppliers() {
    return suppliers;
}

std::vector<ClientOrder>& StepUp::getClientOrders() {
    return clientOrders;
}

std::vector<SupplierOrder>& StepUp::getSupplierOrders() {
    return supplierOrders;
}

Manager& StepUp::getManager() {
    return manager;
}

void StepUp::setManager(const Manager& manager) {
    this->manager = manager;
}

Product& StepUp::findProductById(int id) {
    for (auto& p : products) {
        if (p.getId() == id)
            return p;
    }
    throw std::runtime_error("Product not found.");
}

Supplier& StepUp::findSupplierById(int id) {
    for (auto& s : suppliers) {
        if (s.getId() == id)
            return s;
    }
    throw std::runtime_error("Supplier not found.");
}

void StepUp::addProduct(const Product& product) {
    products.push_back(product);
}

void StepUp::addSupplier(const Supplier& supplier) {
    suppliers.push_back(supplier);
}

void StepUp::addSupplierOrder(const SupplierOrder& order) {
    supplierOrders.push_back(order);
}
