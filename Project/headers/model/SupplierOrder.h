#ifndef SUPPLIERORDER_H
#define SUPPLIERORDER_H

#include <string>
#include <vector>
#include "Supplier.h"
#include "Product.h"

class SupplierOrder {
private:
    int orderNumber;
    std::string date;
    Supplier supplier;
    std::vector<Product> products;

public:
    SupplierOrder(int number, const std::string& date, const Supplier& supplier);

    int getOrderNumber() const;
    std::string getDate() const;
    Supplier getSupplier() const;
    std::vector<Product> getProducts() const;

    void addProduct(const Product& product);
};

#endif // SUPPLIERORDER_H
