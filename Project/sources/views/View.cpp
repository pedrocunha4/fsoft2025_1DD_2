#include <iostream>
#include "../../headers/views/View.h"

void View::showMainMenu() {
    std::cout << "\n=== StepUp Store ===\n";
    std::cout << "1. Client Area\n";
    std::cout << "2. Manager Area\n";
    std::cout << "0. Exit\n";
}

int View::askMainOption() {
    int option;
    std::cout << "Select an option: ";
    std::cin >> option;
    return option;
}

void View::showClientMenu() {
    std::cout << "\n--- Client Menu ---\n";
    std::cout << "1. View Products\n";
    std::cout << "2. Login\n";
    std::cout << "3. Sign Up\n";
    std::cout << "0. Back\n";
}

int View::askClientOption() {
    int option;
    std::cout << "Select an option: ";
    std::cin >> option;
    return option;
}

void View::showManagerMenu() {
    std::cout << "\n--- Manager Menu ---\n";
    std::cout << "1. Login\n";
    std::cout << "0. Back\n";
}

int View::askManagerOption() {
    int option;
    std::cout << "Select an option: ";
    std::cin >> option;
    return option;
}
