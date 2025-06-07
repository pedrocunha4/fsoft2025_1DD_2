#include "gtest/gtest.h"
#include "../Project/headers/model/Manager.h"

TEST(ManagerTest, ShouldCreateManagerWithEmailAndPassword) {
    Manager m("admin@example.com", "secure123");

    EXPECT_EQ(m.getEmail(), "admin@example.com");
    EXPECT_EQ(m.getPassword(), "secure123");
}

TEST(ManagerTest, ShouldInitializeDefaultManager) {
    Manager m;
    EXPECT_EQ(m.getEmail(), "");
    EXPECT_EQ(m.getPassword(), "");
}
