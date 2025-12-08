#include "contact.h"
#include <iostream>

Contact::Contact() : name("Unknown"), phoneNumber("") {}

Contact::Contact(const std::string& name, const std::string& phoneNumber)
    : name(name) {
    if (validatePhoneNumber(phoneNumber)) {
        this->phoneNumber = phoneNumber;
    }
    else {
        this->phoneNumber = "";
        std::cout << "Неверный формат номера: " << phoneNumber
            << " (должен быть: +7 0000000000)" << std::endl;
    }
}

bool Contact::validatePhoneNumber(const std::string& number) {
    // Проверяем формат: +7 10цифр
    std::regex pattern(R"(^\+\d\s\d{10}$)");
    return std::regex_match(number, pattern);
}

std::string Contact::getName() const {
    return name;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

void Contact::display() const {
    std::cout << name << ": " << phoneNumber << std::endl;
}

bool Contact::matches(const std::string& search) const {
    return (name == search) || (phoneNumber == search);
}