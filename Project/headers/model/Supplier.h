#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Supplier {
private:
    int id;
    std::string name;
    std::string contact;
    std::string email;

public:
    Supplier(int id,const std::string& name, const std::string& contact, const std::string& email);
    int getId() const;
    std::string getName() const;
    std::string getContact() const;
    std::string getEmail() const;

    void setContact(const std::string& newContact);
    void setEmail(const std::string& newEmail);
};

#endif // SUPPLIER_H
