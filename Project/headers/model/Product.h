#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    int id;  // Novo campo para o ID
    std::string name;
    std::string brand;
    int stock;
    std::string category;
    std::string description;
    float priceSupplier;
    float priceClient;

public:
    Product();
    Product(int id, const std::string& name, const std::string& brand, int stock,
            const std::string& category, const std::string& description,
            float priceSupplier, float priceClient);

    int getId() const;
    std::string getName() const;
    std::string getBrand() const;
    int getStock() const;
    std::string getCategory() const;
    std::string getDescription() const;
    float getPriceClient() const;
    float getPriceSupplier() const; // usado só pelo gerente
    void reduceStock(int quantity);

    void setName(const std::string& newName);
    void setBrand(const std::string& newBrand);
    void setStock(int newStock);
    void setCategory(const std::string& newCategory);
    void setDescription(const std::string& newDesc);
    void setPriceSupplier(float newPrice);
    void setPriceClient(float newPrice);
    void increaseStock(int quantity);

};

#endif // PRODUCT_H
