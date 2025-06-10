#include "gtest/gtest.h"
#include "../Project/headers/model/SupplierOrder.h"
#include "../Project/headers/model/Supplier.h"
#include "../Project/headers/model/Product.h"

TEST(SupplierOrderTest, ShouldCreateOrderWithSupplierAndDate) {
    Supplier s(1, "Nike", "Rua A", "nike@email.com");
    SupplierOrder order(101, "2024-06-10", s);

    EXPECT_EQ(order.getOrderNumber(), 101);
    EXPECT_EQ(order.getDate(), "2024-06-10");
    EXPECT_EQ(order.getSupplier().getName(), "Nike");
    EXPECT_FALSE(order.getStatus());
    EXPECT_TRUE(order.getProducts().empty());
}

TEST(SupplierOrderTest, ShouldAddProductsToOrder) {
    Supplier s(2, "Adidas", "Rua B", "adidas@email.com");
    SupplierOrder order(102, "2024-06-11", s);

    Product p1(1, "Chuteira", "Adidas", 5, "Futebol", "Top", 25.0f, 60.0f);
    Product p2(2, "Meias", "Adidas", 10, "Acessório", "Confortáveis", 2.0f, 5.0f);

    order.addProduct(p1);
    order.addProduct(p2);

    ASSERT_EQ(order.getProducts().size(), 2);
    EXPECT_EQ(order.getProducts()[0].getName(), "Chuteira");
}

TEST(SupplierOrderTest, ShouldMarkOrderAsCompleted) {
    Supplier s(3, "Puma", "Rua C", "puma@email.com");
    SupplierOrder order(103, "2024-06-12", s);

    EXPECT_FALSE(order.getStatus());
    order.markCompleted();
    EXPECT_TRUE(order.getStatus());
}
