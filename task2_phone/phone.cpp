#include "phone.h"
#include <iostream>

Phone::Phone() {
    // Добавляем несколько тестовых контактов
    addContact("Иван", "+7 9123456789");
    addContact("Мария", "+7 9876543210");
    addContact("Служба спасения", "112");
}

Contact* Phone::findContact(const std::string& search) {
    for (auto& contact : contacts) {
        if (contact.matches(search)) {
            return &contact;
        }
    }
    return nullptr;
}

void Phone::addContact(const std::string& name, const std::string& phoneNumber) {
    Contact newContact(name, phoneNumber);
    if (!newContact.getPhoneNumber().empty()) {
        contacts.push_back(newContact);
        std::cout << "Контакт добавлен: ";
        newContact.display();
    }
}

void Phone::call(const std::string& target) {
    Contact* contact = findContact(target);

    if (contact) {
        std::cout << "Звонок " << contact->getName()
            << " на номер " << contact->getPhoneNumber() << "..." << std::endl;
        std::cout << "Гудки..." << std::endl;
    }
    else {
        // Если не нашли контакт, возможно это прямой номер
        std::cout << "Звонок на номер " << target << "..." << std::endl;
        std::cout << "Гудки..." << std::endl;
    }
}

void Phone::sendSMS(const std::string& target, const std::string& message) {
    Contact* contact = findContact(target);

    if (contact) {
        std::cout << "Отправка SMS " << contact->getName()
            << " (" << contact->getPhoneNumber() << "):" << std::endl;
        std::cout << "Сообщение: " << message << std::endl;
        std::cout << "SMS отправлено!" << std::endl;
    }
    else {
        std::cout << "Отправка SMS на номер " << target << ":" << std::endl;
        std::cout << "Сообщение: " << message << std::endl;
        std::cout << "SMS отправлено!" << std::endl;
    }
}

void Phone::listContacts() const {
    std::cout << std::endl << "=== Контакты ===" << std::endl;
    if (contacts.empty()) {
        std::cout << "Телефонная книга пуста." << std::endl;
    }
    else {
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". ";
            contacts[i].display();
        }
    }
    std::cout << "================" << std::endl << std::endl;
}