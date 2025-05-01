#include "../../headers/model/StepUp.h"

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
