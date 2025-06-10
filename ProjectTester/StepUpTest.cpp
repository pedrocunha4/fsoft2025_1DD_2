#include "gtest/gtest.h"
#include "../Project/headers/model/StepUp.h"

TEST(StepUpTest, ShouldAddAndRetrieveProducts) {
    StepUp app;
    Product p(1, "Tênis", "Nike", 10, "Desporto", "Confortáveis", 20.0f, 50.0f);

    app.addProduct(p);
    ASSERT_EQ(app.getProducts().size(), 1);
    EXPECT_EQ(app.getProducts()[0].getName(), "Tênis");
}

TEST(StepUpTest, ShouldFindProductById) {
    StepUp app;
    Product p(2, "Chuteira", "Adidas", 5, "Futebol", "Top", 30.0f, 70.0f);
    app.addProduct(p);

    Product& found = app.findProductById(2);
    EXPECT_EQ(found.getBrand(), "Adidas");
}

TEST(StepUpTest, ShouldThrowIfProductNotFound) {
    StepUp app;
    EXPECT_THROW(app.findProductById(999), std::runtime_error);
}

TEST(StepUpTest, ShouldAddSupplierAndRetrieve) {
    StepUp app;
    Supplier s(1, "Nike", "Rua A", "nike@email.com");

    app.addSupplier(s);
    ASSERT_EQ(app.getSuppliers().size(), 1);
    EXPECT_EQ(app.getSuppliers()[0].getName(), "Nike");
}

TEST(StepUpTest, ShouldFindSupplierById) {
    StepUp app;
    Supplier s(3, "Puma", "Rua C", "puma@email.com");
    app.addSupplier(s);

    Supplier& found = app.findSupplierById(3);
    EXPECT_EQ(found.getEmail(), "puma@email.com");
}

TEST(StepUpTest, ShouldThrowIfSupplierNotFound) {
    StepUp app;
    EXPECT_THROW(app.findSupplierById(888), std::runtime_error);
}

TEST(StepUpTest, ShouldAssignManagerCorrectly) {
    StepUp app;
    Manager m("admin@example.com", "adminpass");

    app.setManager(m);
    EXPECT_EQ(app.getManager().getEmail(), "admin@example.com");
}
