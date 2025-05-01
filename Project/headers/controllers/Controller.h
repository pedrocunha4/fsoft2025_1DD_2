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

    // Ações do cliente
    void loginClient();
    void signUpClient();
    void viewProductsGuest();

    // Carrinho
    void addToCart(Cart& cart);
    void viewCart(Cart& cart);
    void removeFromCart(Cart& cart);
    void completeOrder(Cart& cart);

    // Autenticação
    bool isAuthenticated();
};

#endif // CONTROLLER_H
