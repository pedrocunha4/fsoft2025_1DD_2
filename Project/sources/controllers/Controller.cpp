#include <iostream>
#include <iomanip>
#include <fstream>
#include "../../headers/controllers/Controller.h"
#include "../../headers/views/View.h"
#include "../../headers/views/Utils.h"
#include "../../headers/model/Cart.h"
#include "../../headers/model/Product.h"

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

void Controller::viewProductsGuest() {
    const auto& products = store.getProducts();
    int option;

    // 🔐 Determinar qual carrinho usar
    Cart* cartPtr = nullptr;
    if (isAuthenticated()) {
        cartPtr = &clientCarts[loggedInClient->getEmail()];
    } else {
        static Cart guestCart;  // carrinho temporário para clientes não logados
        cartPtr = &guestCart;
    }

    Cart& cart = *cartPtr;  // referência ao carrinho correto

    std::cout << "\n--- Available Products ---\n";

    if (products.empty()) {
        std::cout << "No products available.\n";
        return;
    }

    for (const Product& p : products) {
        std::cout << "ID: " << p.getId() << "\n";
        std::cout << "Name: " << p.getName() << "\n";
        std::cout << "Brand: " << p.getBrand() << "\n";
        std::cout << "Category: " << p.getCategory() << "\n";
        std::cout << "Description: " << p.getDescription() << "\n";
        std::cout << "Price: " << std::fixed << std::setprecision(2)
                  << p.getPriceClient() << " EUR\n";
        std::cout << "Stock: " << p.getStock() << "\n";
        std::cout << "--------------------------\n";
    }

    do {
        std::cout << "1. Add to cart\n";
        std::cout << "2. View cart\n";
        std::cout << "0. Back to menu\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                addToCart(cart);
            break;
            case 2:
                viewCart(cart);
            break;
            case 0:
                std::cout << "Returning...\n";
            break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (option != 0);
}

void Controller::loginClient() {
    std::string email, password;
    bool found = false;

    std::cout << "\n--- Client Login ---\n";
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;

    for (Client& c : store.getClients()) {
        if (c.getEmail() == email && c.getPassword() == password) {
            std::cout << "Login successful! Welcome back, " << email << ".\n";
            loggedInClient = &c;  // <- guardar o cliente autenticado
            found = true;
            runClientLoggedMenu();
            break;
        }
    }

    if (!found) {
        std::cout << "Invalid email or password. Please try again.\n";
    }
}

void Controller::runClientLoggedMenu() {
    if (!isAuthenticated()) {
        std::cout << "Access denied. Please login first.\n";
        return;
    }

    Cart& cart = clientCarts[loggedInClient->getEmail()];  // Carrinho pessoal do cliente

    int option;
    do {
        std::cout << "\n--- Client Menu ---\n";
        std::cout << "1 - View products\n";
        std::cout << "2 - View cart\n";
        std::cout << "3 - View orders\n";
        std::cout << "0 - Logout\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                viewProductsGuest();
            break;
            case 2:
                viewCart(cart);
            break;
            case 3:
                // TODO: mostrar histórico de encomendas
                    std::cout << "[View orders] Not implemented yet.\n";
            break;
            case 0:
                std::cout << "Logging out...\n";
            loggedInClient = nullptr;  // Efetua logout
            break;
            default:
                std::cout << "Invalid option.\n";
        }
    } while (option != 0);
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

    // Guardar cliente no ficheiro
    std::ofstream outFile("clients.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << email << " " << password << "\n";
        outFile.close();
    } else {
        std::cout << "Error saving client to file.\n";
    }

    std::cout << "Account created successfully!\n";
}

void Controller::addToCart(Cart& cart) {
    int productId;
    int quantity;

    std::cout << "Enter the product ID: ";
    std::cin >> productId;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    // Encontrar o produto pelo ID
    for (const Product& p : store.getProducts()) {
        if (p.getId() == productId) {
            if (quantity > p.getStock()) {
                std::cout << "Error: Only " << p.getStock() << " units in stock.\n";
                return;
            }

            cart.addProduct(p, quantity);
            std::cout << "Product added to cart.\n";
            return;
        }
    }

    std::cout << "Product not found.\n";
}

void Controller::viewCart(Cart& cart) {
    int option;
    do {
        cart.showCart();  // Exibir o carrinho

        std::cout << "\n--- Menu Cart ---\n";
        std::cout << "1. Delete product\n";
        std::cout << "2. Complete order\n";
        std::cout << "0. Go back to products menu\n";
        std::cout << "Option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                removeFromCart(cart);  // Remover produto
            break;
            case 2:
                completeOrder(cart);  // Finalizar a encomenda
            break;
            case 0:
                std::cout << "Returning to products menu...\n";
            break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 0);  // Continua no menu do carrinho até o cliente escolher "0"
}

void Controller::removeFromCart(Cart& cart) {
    int productId;
    std::cout << "Enter the product ID to remove: ";
    std::cin >> productId;

    cart.removeProductById(productId);
}

void Controller::completeOrder(Cart& cart) {
    if (cart.isEmpty()) {
        std::cout << "Your cart is empty! Cannot complete order.\n";
        return;
    }

    if (!isAuthenticated()) {
        std::cout << "You must be logged in to complete the order.\n";
        return;
    }

    // Subtrair stock
    for (const auto& item : cart.getItems()) {
        Product& product = store.findProductById(item.first.getId());
        if (item.second > product.getStock()) {
            std::cout << "Error: Product " << product.getName() << " doesn't have enough stock.\n";
            return;
        }
        product.reduceStock(item.second);
    }

    std::cout << "Order completed successfully!\n";
    cart.clear();
}

// Função para verificar se o cliente está autenticado
bool Controller::isAuthenticated() {
    return loggedInClient != nullptr;
}



void Controller::runManager() {
    std::cout << "[Manager logic placeholder] To be implemented...\n";
    // Ex: showManagerMenu(), handle login, etc.
}
