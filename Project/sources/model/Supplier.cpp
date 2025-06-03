#include "Supplier.h"

Supplier::Supplier(const std::string& name, const std::string& contact, const std::string& email)
        : name(name), contact(contact), email(email) {}

std::string Supplier::getName() const {
    return name;
}

std::string Supplier::getContact() const {
    return contact;
}

std::string Supplier::getEmail() const {
    return email;
}

void Supplier::setContact(const std::string& newContact) {
    contact = newContact;
}

void Supplier::setEmail(const std::string& newEmail) {
    email = newEmail;
}
