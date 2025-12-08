#include <iostream>
#include <string>
#include "phone.h"

void showHelp() {
    std::cout << "\n=== Мобильный телефон ===\n";
    std::cout << "Доступные команды:\n";
    std::cout << "  add <имя> <номер>   - добавить контакт\n";
    std::cout << "                       пример: add Иван +7 9123456789\n";
    std::cout << "  call <имя/номер>    - позвонить\n";
    std::cout << "  sms <имя/номер>     - отправить SMS\n";
    std::cout << "  list                - показать все контакты\n";
    std::cout << "  help                - показать эту справку\n";
    std::cout << "  exit                - выход\n";
    std::cout << "==========================\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    Phone phone;
    std::string command;

    std::cout << "=== Добро пожаловать в мобильный телефон! ===\n";
    showHelp();

    while (true) {
        std::cout << "\n> ";
        std::cin >> command;

        if (command == "add") {
            std::string name, number;
            std::cin >> name >> number;
            phone.addContact(name, number);
        }
        else if (command == "call") {
            std::string target;
            std::cin >> target;
            phone.call(target);
        }
        else if (command == "sms") {
            std::string target;
            std::cin >> target;

            std::string message;
            std::cout << "Введите сообщение: ";
            std::getline(std::cin >> std::ws, message);

            phone.sendSMS(target, message);
        }
        else if (command == "list") {
            phone.listContacts();
        }
        else if (command == "help") {
            showHelp();
        }
        else if (command == "exit") {
            std::cout << "Выключение телефона...\n";
            break;
        }
        else {
            std::cout << "Неизвестная команда. Введите 'help' для справки.\n";
        }
    }

    return 0;
}