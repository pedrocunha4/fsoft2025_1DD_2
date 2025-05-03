#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "ClientOrder.h"

class Client {
private:
    std::string email;
    std::string password;
    std::vector<ClientOrder> orders;

public:
    Client(); // vazio
    Client(const std::string& email, const std::string& password);

    std::string getEmail() const;
    std::string getPassword() const;
    void addOrder(const ClientOrder& order);
    const std::vector<ClientOrder>& getOrders() const;

};

#endif // CLIENT_H