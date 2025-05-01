#include <iostream>
#include "../../headers/controllers/Controller.h"
#include "../../headers/views/View.h"

Controller::Controller(StepUp &store) : store(store) {}

void Controller::run() {
    int option;
    do {
        View::showMainMenu();
        option = View::askMainOption();

        switch (option) {
            case 1:
                runClient();
            break;
            case 2:
                runManager();
            break;
            case 0:
                std::cout << "Exiting StepUp Store...\n";
            break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while (option != 0);
}

#include "../../headers/controllers/Controller.h"
#include "../../headers/views/View.h"

void Controller::runClient() {
    int option;
    do {
        View::showClientMenu();
        option = View::askClientOption();

        switch (option) {
            case 1:
                viewProductsGuest();
            break;
            case 2:
                loginClient();
            break;
            case 3:
                signUpClient();
            break;
            case 0:
                std::cout << "Returning to main menu...\n";
            break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (option != 0);
}

// Placeholder functions
void Controller::viewProductsGuest() {
    std::cout << "[Guest] Showing available products...\n";
}

void Controller::loginClient() {
    std::cout << "[Client] Login not implemented yet.\n";
}

void Controller::signUpClient() {
    std::cout << "[Client] Sign up not implemented yet.\n";
}


void Controller::runManager() {
    std::cout << "[Manager logic placeholder] To be implemented...\n";
    // Ex: showManagerMenu(), handle login, etc.
}
