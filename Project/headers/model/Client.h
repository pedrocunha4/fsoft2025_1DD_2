#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string email;
    std::string password;

public:
    Client(); // vazio
    Client(const std::string& email, const std::string& password);

    std::string getEmail() const;
    std::string getPassword() const;
};

#endif // CLIENT_H