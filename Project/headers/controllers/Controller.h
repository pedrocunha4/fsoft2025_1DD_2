#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/StepUp.h"

class Controller {
private:
    StepUp &store;

public:
    Controller(StepUp &store);
    void run();

    void runClient();   // submenu para cliente
    void runManager();  // submenu para gerente
    void loginClient();
    void signUpClient();
    void viewProductsGuest(); // sem login

};

#endif // CONTROLLER_H
