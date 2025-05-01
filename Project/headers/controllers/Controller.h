#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/StepUp.h"
#include "../model/Cart.h"

    class Controller {
    private:
        StepUp &store;
        Client* loggedInClient = nullptr; // <- ponteiro para o cliente autenticado
    public:
        Controller(StepUp &store);
        void run();

        void runClient();   // submenu para cliente
        void runManager();  // submenu para gerente
        void loginClient();
        void signUpClient();
        void viewProductsGuest();
        void runClientLoggedMenu();

        void addToCart(Cart& cart);
        void viewCart(Cart& cart);
        void removeFromCart(Cart& cart);
        void completeOrder(Cart& cart);
        bool isAuthenticated();

    };

#endif // CONTROLLER_H
