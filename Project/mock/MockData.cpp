#include "MockData.h"
#include "../headers/model/Product.h"
#include "../headers/model/Client.h"
#include "../headers/model/Manager.h"
#include "../headers/model/Supplier.h"
#include "../headers/model/SupplierOrder.h"

#include <fstream>

void MockData::generateData(StepUp& store) {
    // Adicionar suppliers
    Supplier nike(1, "Nike", "123456789", "nike@supply.com");
    Supplier adidas(2, "Adidas", "987654321", "adidas@supply.com");
    Supplier puma(3, "Puma", "222333444", "puma@supply.com");

    store.getSuppliers().push_back(nike);
    store.getSuppliers().push_back(adidas);
    store.getSuppliers().push_back(puma);

    // Adicionar produtos com suppliers associados
    store.getProducts().push_back(Product(1, "Nike Air Max", "Nike", 12, "Running",
                                          "Comfortable running shoes", 50.0f, 89.99f, nike));
    store.getProducts().push_back(Product(2, "Adidas Ultraboost", "Adidas", 8, "Running",
                                          "High-performance footwear", 60.0f, 119.90f, adidas));
    store.getProducts().push_back(Product(3, "Puma RS-X", "Puma", 15, "Sports",
                                          "Sporty, stylish and comfortable", 55.0f, 99.99f, puma));

    // Produtos sem supplier real
    store.getProducts().push_back(Product(4, "Converse All Star", "Converse", 10, "Casual",
                                          "Iconic canvas sneakers", 25.0f, 59.99f));
    store.getProducts().push_back(Product(5, "New Balance 574", "New Balance", 7, "Lifestyle",
                                          "Retro-inspired design with modern comfort", 45.0f, 84.50f));
    store.getProducts().push_back(Product(6, "Reebok Classic Leather", "Reebok", 9, "Casual",
                                          "Iconic and comfortable leather sneakers", 40.0f, 79.99f));
    store.getProducts().push_back(Product(7, "Asics Gel-Kayano", "Asics", 5, "Running",
                                          "Gel-cushioned high-performance running shoes", 75.0f, 139.99f));
    store.getProducts().push_back(Product(8, "Vans Old Skool", "Vans", 20, "Casual",
                                          "Classic skate sneakers", 35.0f, 69.99f));
    store.getProducts().push_back(Product(9, "Under Armour HOVR", "Under Armour", 10, "Running",
                                          "Advanced cushioning for running", 65.0f, 120.00f));
    store.getProducts().push_back(Product(10, "Skechers Go Walk", "Skechers", 12, "Casual",
                                          "Walking shoes with ultimate comfort", 30.0f, 59.99f));

    // Adicionar clientes
    store.getClients().push_back(Client("pedro@gmail.com", "1234"));
    store.getClients().push_back(Client("raul@gmail.com", "1234"));
    store.getClients().push_back(Client("ber@gmail.com", "1234"));
    store.getClients().push_back(Client("wessa@gmail.com", "1234"));

    // Adicionar manager
    store.setManager(Manager("admin1@stepup.com", "admin777"));

    // Encontrar referências aos clientes
    Client& pedro = store.getClients()[0];
    Client& raul = store.getClients()[1];

    // Produtos para usar nas orders
    Product nikeProd = store.findProductById(1);
    Product adidasProd = store.findProductById(2);
    Product pumaProd = store.findProductById(3);
    Product converseProd = store.findProductById(4);

    // 1. Produtos no "carrinho" do Pedro (representado como order pendente)
    std::vector<std::pair<Product, int>> cartItems;
    cartItems.push_back(std::make_pair(nikeProd, 1));    // Nike Air Max
    cartItems.push_back(std::make_pair(adidasProd, 1));  // Adidas Ultraboost
    float cartTotal = nikeProd.getPriceClient() + adidasProd.getPriceClient();
    ClientOrder cartOrder(cartItems, cartTotal, false); // pendente
    pedro.addOrder(cartOrder);

    // 2. Orders para Pedro (2 pendentes, 2 confirmadas)
    // Order pendente 1
    std::vector<std::pair<Product, int>> pedroPending1 = {
        {pumaProd, 1}
    };
    ClientOrder pedroOrderPending1(pedroPending1, pumaProd.getPriceClient(), false);
    pedro.addOrder(pedroOrderPending1);

    // Order confirmada 1
    std::vector<std::pair<Product, int>> pedroConfirmed1 = {
        {converseProd, 3}
    };
    float pedroConfirmed1Total = converseProd.getPriceClient() * 3;
    ClientOrder pedroOrderConfirmed1(pedroConfirmed1, pedroConfirmed1Total, true);
    pedro.addOrder(pedroOrderConfirmed1);

    // Order confirmada 2
    std::vector<std::pair<Product, int>> pedroConfirmed2 = {
        {nikeProd, 1}, {adidasProd, 1}
    };
    float pedroConfirmed2Total = nikeProd.getPriceClient() + adidasProd.getPriceClient();
    ClientOrder pedroOrderConfirmed2(pedroConfirmed2, pedroConfirmed2Total, true);
    pedro.addOrder(pedroOrderConfirmed2);

    // 3. Orders para Raul (2 confirmadas)
    std::vector<std::pair<Product, int>> raulOrder1 = {
        {adidasProd, 2}
    };
    float raulOrder1Total = adidasProd.getPriceClient() * 2;
    ClientOrder raulConfirmed1(raulOrder1, raulOrder1Total, true);
    raul.addOrder(raulConfirmed1);

    std::vector<std::pair<Product, int>> raulOrder2 = {
        {pumaProd, 1}, {converseProd, 2}
    };
    float raulOrder2Total = pumaProd.getPriceClient() + converseProd.getPriceClient() * 2;
    ClientOrder raulConfirmed2(raulOrder2, raulOrder2Total, true);
    raul.addOrder(raulConfirmed2);

    // 4. SupplierOrders (3 pending, 3 completed)
    SupplierOrder order1(1, "2024-06-01", nike);
    order1.addProduct(nikeProd);
    order1.addProduct(nikeProd);  // 2 units
    store.getSupplierOrders().push_back(order1);

    SupplierOrder order2(2, "2024-06-03", adidas);
    order2.addProduct(adidasProd);
    order2.addProduct(adidasProd);
    store.getSupplierOrders().push_back(order2);

    SupplierOrder order3(3, "2024-06-05", puma);
    order3.addProduct(pumaProd);
    order3.addProduct(converseProd);
    store.getSupplierOrders().push_back(order3);

    // Completed supplier orders
    SupplierOrder completed1(4, "2024-06-10", nike);
    completed1.addProduct(nikeProd);
    completed1.markCompleted();
    store.getSupplierOrders().push_back(completed1);

    SupplierOrder completed2(5, "2024-06-12", adidas);
    completed2.addProduct(adidasProd);
    completed2.addProduct(converseProd);
    completed2.markCompleted();
    store.getSupplierOrders().push_back(completed2);

    SupplierOrder completed3(6, "2024-06-15", puma);
    completed3.addProduct(pumaProd);
    completed3.addProduct(nikeProd);
    completed3.markCompleted();
    store.getSupplierOrders().push_back(completed3);
}
