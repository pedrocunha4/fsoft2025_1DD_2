#include "gtest/gtest.h"
#include "../Project/headers/model/Supplier.h"

TEST(SupplierTest, ShouldCreateSupplierWithAllFields) {
    Supplier s(1, "Nike", "Rua Central", "nike@example.com");

    EXPECT_EQ(s.getId(), 1);
    EXPECT_EQ(s.getName(), "Nike");
    EXPECT_EQ(s.getContact(), "Rua Central");
    EXPECT_EQ(s.getEmail(), "nike@example.com");
}

TEST(SupplierTest, ShouldUpdateEmailCorrectly) {
    Supplier s(2, "Adidas", "Rua Sport", "old@adidas.com");
    s.setEmail("new@adidas.com");

    EXPECT_EQ(s.getEmail(), "new@adidas.com");
}
