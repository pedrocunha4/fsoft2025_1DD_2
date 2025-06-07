#include "gtest/gtest.h"
#include "../Project/headers/model/Client.h"
#include "../Project/headers/model/ClientOrder.h"
#include "../Project/headers/model/Product.h"

TEST(ClientTest, ShouldAddOrderToClient) {
    Client c("client@example.com", "1234");

    std::vector<std::pair<Product, int>> items = {
        { Product(1, "Tênis", "Nike", 5, "Desporto", "Confortável", 20.0f, 40.0f), 2 }
    };

    ClientOrder order(items, 80.0f, false);
    c.addOrder(order);

    ASSERT_EQ(c.getOrders().size(), 1);
    EXPECT_FLOAT_EQ(c.getOrders()[0].getTotal(), 80.0f);
    EXPECT_FALSE(c.getOrders()[0].isDelivered());
}
