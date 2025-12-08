#pragma once
#include "contact.h"
#include <vector>
#include <string>

class Phone {
private:
    std::vector<Contact> contacts;

    Contact* findContact(const std::string& search);

public:
    Phone();

    void addContact(const std::string& name, const std::string& phoneNumber);
    void call(const std::string& target);
    void sendSMS(const std::string& target, const std::string& message);
    void listContacts() const;
};