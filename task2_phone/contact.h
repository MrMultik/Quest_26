#pragma once
#include <string>
#include <regex>

class Contact {
private:
    std::string name;
    std::string phoneNumber;

    bool validatePhoneNumber(const std::string& number);

public:
    Contact();
    Contact(const std::string& name, const std::string& phoneNumber);

    std::string getName() const;
    std::string getPhoneNumber() const;

    void display() const;
    bool matches(const std::string& search) const;
};