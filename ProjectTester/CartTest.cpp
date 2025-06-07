#include "gtest/gtest.h"
#include "../Project/headers/model/Cart.h"
#include "../Project/headers/model/Product.h"
#include "../Project/headers/model/Supplier.h"

TEST(CartTest, ShouldAddProductCorrectly) {
    Cart cart;
    Product p(1, "Tênis", "Nike", 10, "Desporto", "Leves", 20.0f, 40.0f);
    cart.addProduct(p, 2);

    ASSERT_FALSE(cart.isEmpty());
    ASSERT_EQ(cart.getItems().size(), 1);
    EXPECT_EQ(cart.getItems()[0].second, 2);  // quantidade
}

TEST(CartTest, ShouldAccumulateSameProductQuantity) {
    Cart cart;
    Product p(1, "Tênis", "Nike", 10, "Desporto", "Leves", 20.0f, 40.0f);
    cart.addProduct(p, 2);
    cart.addProduct(p, 3);  // mesmo nome = acumular quantidade

    ASSERT_EQ(cart.getItems().size(), 1);
    EXPECT_EQ(cart.getItems()[0].second, 5);
}

TEST(CartTest, ShouldReturnCorrectTotalPrice) {
    Cart cart;
    Product p1(1, "Tênis", "Nike", 10, "Desporto", "Leves", 20.0f, 50.0f);
    Product p2(2, "Chuteira", "Adidas", 8, "Futebol", "Pro", 30.0f, 70.0f);

    cart.addProduct(p1, 1);  // 50
    cart.addProduct(p2, 2);  // 140

    EXPECT_FLOAT_EQ(cart.getTotal(), 190.0f);
}

TEST(CartTest, ShouldClearCart) {
    Cart cart;
    Product p(1, "Tênis", "Nike", 10, "Desporto", "Leves", 20.0f, 40.0f);
    cart.addProduct(p, 2);

    cart.clear();
    EXPECT_TRUE(cart.isEmpty());
    EXPECT_EQ(cart.getItems().size(), 0);
}
