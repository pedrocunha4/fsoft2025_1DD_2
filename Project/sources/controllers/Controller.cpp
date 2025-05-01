#include <iostream>
#include "../../headers/controllers/Controller.h"
#include "../../headers/views/View.h"
#include "../../headers/views/Utils.h"

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
    std::string email, password;
    bool found = false;

    std::cout << "\n--- Client Login ---\n";
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;

    for (const Client& c : store.getClients()) {
        if (c.getEmail() == email && c.getPassword() == password) {
            std::cout << "Login successful! Welcome back, " << email << ".\n";
            found = true;

            // TODO: chamar menu do cliente autenticado
            // runClientLoggedMenu(c);
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid email or password. Please try again.\n";
    }
}


void Controller::signUpClient() {
    std::string email, password;

    std::cout << "\n--- Sign Up ---\n";
    std::cout << "Email: ";
    std::cin >> email;

    // Verificar formato do email
    if (!Utils::isValidEmail(email)) {
        std::cout << "Invalid email format. Use something like: XXXXXX@gmail.com\n";
        return;
    }

    // Verificar se já existe
    for (const Client& c : store.getClients()) {
        if (c.getEmail() == email) {
            std::cout << "An account with that email already exists.\n";
            return;
        }
    }

    std::cout << "Password: ";
    std::cin >> password;

    // Verificar tamanho mínimo da password
    if (password.length() < 4) {
        std::cout << "Password must have at least 4 characters.\n";
        return;
    }

    Client newClient(email, password);
    store.getClients().push_back(newClient);

    std::cout << "Account created successfully!\n";
}


void Controller::runManager() {
    std::cout << "[Manager logic placeholder] To be implemented...\n";
    // Ex: showManagerMenu(), handle login, etc.
}
