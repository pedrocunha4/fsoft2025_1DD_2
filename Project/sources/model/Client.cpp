#include "../../headers/model/Client.h"

Client::Client() {}

Client::Client(const std::string& email, const std::string& password)
    : email(email), password(password) {}

std::string Client::getEmail() const {
    return email;
}

std::string Client::getPassword() const {
    return password;
}
