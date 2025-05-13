#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class Manager {
private:
    std::string email;
    std::string password;

public:
    Manager();
    Manager(const std::string& email, const std::string& password);

    std::string getEmail() const;
    std::string getPassword() const;
};

#endif // MANAGER_H
