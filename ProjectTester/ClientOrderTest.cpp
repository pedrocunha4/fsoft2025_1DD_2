#include "gtest/gtest.h"
#include "../Project/headers/model/ClientOrder.h"
#include "../Project/headers/model/Product.h"

TEST(ClientOrderTest, ShouldStoreItemsCorrectly) {
    std::vector<std::pair<Product, int>> items = {
        { Product(1, "Tênis", "Nike", 5, "Desporto", "Leves", 20.0f, 40.0f), 2 },
        { Product(2, "Chuteira", "Adidas", 3, "Futebol", "Pro", 30.0f, 70.0f), 1 }
    };

    ClientOrder order(items, 150.0f);  // total = 80 + 70

    EXPECT_EQ(order.getItems().size(), 2);
    EXPECT_FLOAT_EQ(order.getTotal(), 150.0f);
    EXPECT_FALSE(order.isDelivered());
}

TEST(ClientOrderTest, ShouldUpdateDeliveryStatus) {
    ClientOrder order({}, 0.0f);
    EXPECT_FALSE(order.isDelivered());

    order.setDelivered(true);
    EXPECT_TRUE(order.isDelivered());
}
