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
    Manager manager;
    std::vector<Supplier> suppliers;
    std::vector<ClientOrder> clientOrders;
    std::vector<SupplierOrder> supplierOrders;

public:
    StepUp();

    std::vector<Product>& getProducts();
    std::vector<Client>& getClients();
    Manager& getManager();
    std::vector<Supplier>& getSuppliers();
    std::vector<ClientOrder>& getClientOrders();
    std::vector<SupplierOrder>& getSupplierOrders();
};

#endif // STEPUP_H
