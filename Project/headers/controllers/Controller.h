#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include "../model/StepUp.h"
#include "../model/Cart.h"
#include "../model/Client.h"

class Controller {
private:
    StepUp &store;
    Client* loggedInClient = nullptr;                // Cliente autenticado
    std::map<std::string, Cart> clientCarts;         // Email → Carrinho

public:
    Controller(StepUp &store);
    void run();

    // Áreas principais
    void runClient();
    void runManager();
    void runClientLoggedMenu();
    void loginManager();
    void runManagerMenu();  // (vai ser chamado após login)

    // Ações do cliente
    void loginClient();
    void signUpClient();
    void viewProductsGuest();

    // Carrinho
    void addToCart(Cart& cart);
    void viewCart(Cart& cart);
    void removeFromCart(Cart& cart);
    void completeOrder(Cart& cart);

    //Encomendas
    void showClientOrders();

    // Autenticação
    bool isAuthenticated();

    //Menu manager
    void manageProductsMenu();
    void manageSuppliersMenu();
    void manageClientsMenu();
    void addProduct();
    void editProduct();
    void deleteProduct();
    void listProducts();
    void placeOrderToSupplier();
    void deleteClientByEmail();
    void viewCompletedSupplierOrders();
    void viewSupplierOrders();
    void viewAllClientsOrders();

};

#endif // CONTROLLER_H
