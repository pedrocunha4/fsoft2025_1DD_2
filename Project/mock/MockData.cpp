#include "MockData.h"
#include "../headers/model/Product.h"
#include "../headers/model/Client.h"
#include <fstream>

void MockData::generateData(StepUp& store) {

    store.getProducts().push_back(Product(1, "Nike Air Max", "Nike", 12, "Running",
        "Comfortable running shoes", 50.0f, 89.99f));
    store.getProducts().push_back(Product(2, "Adidas Ultraboost", "Adidas", 8, "Running",
        "High-performance footwear", 60.0f, 119.90f));
    store.getProducts().push_back(Product(3, "Converse All Star", "Converse", 10, "Casual",
        "Iconic canvas sneakers", 25.0f, 59.99f));
    store.getProducts().push_back(Product(4, "Puma RS-X", "Puma", 15, "Sports",
        "Sporty, stylish and comfortable", 55.0f, 99.99f));
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

    // Adicionar clientes (provisorio)
    store.getClients().push_back(Client("pedro@gmail.com", "1234"));
    store.getClients().push_back(Client("raul@gmail.com", "1234"));
    store.getClients().push_back(Client("ber@gmail.com", "1234"));
    store.getClients().push_back(Client("wessa@gmail.com", "1234"));
}
