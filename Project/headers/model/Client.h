#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "ClientOrder.h"

class Client {
private:
    std::string email;
    std::string password;
    std::vector<ClientOrder> orders;
    std::string name;



public:
    Client(); // vazio
    Client(const std::string& email, const std::string& password);

    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;
    void addOrder(const ClientOrder& order);
    std::vector<ClientOrder>& getOrders();
    const std::vector<ClientOrder>& getOrders() const;


};

#endif // CLIENT_H