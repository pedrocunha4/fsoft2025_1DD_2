#ifndef STEPUP_H
#define STEPUP_H

#include <vector>
#include "Product.h"
#include "Client.h"
#include "Manager.h"
#include "Supplier.h"
#include "ClientOrder.h"
#include "SupplierOrder.h"

class StepUp {
private:
    std::vector<Product> products;
    std::vector<Client> clients;
    std::vector<Supplier> suppliers;
    std::vector<ClientOrder> clientOrders;
    std::vector<SupplierOrder> supplierOrders;
    Manager manager;

public:
    StepUp();

    std::vector<Product>& getProducts();
    std::vector<Client>& getClients();
    std::vector<Supplier>& getSuppliers();
    std::vector<ClientOrder>& getClientOrders();
    std::vector<SupplierOrder>& getSupplierOrders();
    Manager& getManager();
    void setManager(const Manager& manager);

    Product& findProductById(int id);
    Supplier& findSupplierById(int id);

    void addProduct(const Product& product);
    void addSupplier(const Supplier& supplier);
    void addSupplierOrder(const SupplierOrder& order);
};

#endif // STEPUP_H
