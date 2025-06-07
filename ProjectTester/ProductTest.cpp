#include "gtest/gtest.h"
#include "../Project/headers/model/Product.h"
#include "../Project/headers/model/Supplier.h"

TEST(ProductTest, ShouldCreateProductWithoutSupplier) {
    Product p(1, "Tênis", "Nike", 10, "Desporto", "Leve e confortável", 20.0f, 40.0f);

    EXPECT_EQ(p.getId(), 1);
    EXPECT_EQ(p.getName(), "Tênis");
    EXPECT_EQ(p.getBrand(), "Nike");
    EXPECT_EQ(p.getStock(), 10);
    EXPECT_EQ(p.getCategory(), "Desporto");
    EXPECT_EQ(p.getDescription(), "Leve e confortável");
    EXPECT_FLOAT_EQ(p.getPriceSupplier(), 20.0f);
    EXPECT_FLOAT_EQ(p.getPriceClient(), 40.0f);
}

TEST(ProductTest, ShouldCreateProductWithSupplier) {
    Supplier s(2, "Adidas", "Rua Central", "adidas@email.com");
    Product p(2, "Chuteira", "Adidas", 5, "Futebol", "Alta performance", 25.0f, 60.0f, s);

    EXPECT_EQ(p.getName(), "Chuteira");
    EXPECT_EQ(p.getSupplier().getName(), "Adidas");
    EXPECT_EQ(p.getSupplier().getEmail(), "adidas@email.com");
}

TEST(ProductTest, ShouldReduceStockSafely) {
    Product p(3, "Botas", "Puma", 8, "Montanha", "Resistente", 30.0f, 70.0f);
    p.reduceStock(3);
    EXPECT_EQ(p.getStock(), 5);

    p.reduceStock(10);  // não deve reduzir porque excede stock
    EXPECT_EQ(p.getStock(), 5);
}

TEST(ProductTest, ShouldIncreaseStock) {
    Product p(4, "Sandálias", "Reef", 2, "Verão", "Conforto máximo", 15.0f, 35.0f);
    p.increaseStock(6);
    EXPECT_EQ(p.getStock(), 8);
}

TEST(ProductTest, ShouldUpdateFieldsCorrectly) {
    Product p;
    p.setName("Novo Produto");
    p.setBrand("Nova Marca");
    p.setStock(50);
    p.setCategory("Lifestyle");
    p.setDescription("Descrição atualizada");
    p.setPriceSupplier(12.5f);
    p.setPriceClient(29.9f);

    EXPECT_EQ(p.getName(), "Novo Produto");
    EXPECT_EQ(p.getBrand(), "Nova Marca");
    EXPECT_EQ(p.getStock(), 50);
    EXPECT_EQ(p.getCategory(), "Lifestyle");
    EXPECT_EQ(p.getDescription(), "Descrição atualizada");
    EXPECT_FLOAT_EQ(p.getPriceSupplier(), 12.5f);
    EXPECT_FLOAT_EQ(p.getPriceClient(), 29.9f);
}
