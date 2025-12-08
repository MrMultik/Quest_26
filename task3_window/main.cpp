#include <iostream>
#include <string>
#include <limits>
#include "window.h"

void showHelp() {
    std::cout << std::endl << "=== Управление окном ===" << std::endl;
    std::cout << "Доступные команды:" << std::endl;
    std::cout << "  move <dx> <dy>    - переместить окно" << std::endl;
    std::cout << "                     пример: move 5 -3" << std::endl;
    std::cout << "  resize <w> <h>    - изменить размер" << std::endl;
    std::cout << "                     пример: resize 40 20" << std::endl;
    std::cout << "  display           - показать экран с окном" << std::endl;
    std::cout << "  info              - показать информацию об окне" << std::endl;
    std::cout << "  help              - показать эту справку" << std::endl;
    std::cout << "  close             - закрыть окно (выход)" << std::endl;
    std::cout << "========================" << std::endl << std::endl;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Устанавливаем русскую локаль для корректного отображения
    setlocale(LC_ALL, "Russian");

    // Создаем окно с начальными параметрами
    Window window(20, 10, 40, 20);
    std::string command;

    std::cout << "=== Система управления окном рабочего стола ===" << std::endl;
    std::cout << "Размер экрана: " << Screen::WIDTH << "x" << Screen::HEIGHT << " пикселей" << std::endl;
    std::cout << "Окно создано: позиция(20,10) размер(40x20)" << std::endl;
    showHelp();

    while (window.isWindowOpen()) {
        std::cout << std::endl << "> ";
        std::cin >> command;

        if (command == "move") {
            int dx, dy;
            if (std::cin >> dx >> dy) {
                window.move(dx, dy);
                clearInput();
            }
            else {
                std::cout << "Неверные параметры! Используйте: move <dx> <dy>" << std::endl;
                clearInput();
            }
        }
        else if (command == "resize") {
            int width, height;
            if (std::cin >> width >> height) {
                window.resize(width, height);
                clearInput();
            }
            else {
                std::cout << "Неверные параметры! Используйте: resize <ширина> <высота>" << std::endl;
                clearInput();
            }
        }
        else if (command == "display") {
            window.display();
            clearInput();
        }
        else if (command == "info") {
            window.getInfo();
            clearInput();
        }
        else if (command == "help") {
            showHelp();
            clearInput();
        }
        else if (command == "close") {
            window.close();
            clearInput();
        }
        else {
            std::cout << "Неизвестная команда '" << command
                << "'. Введите 'help' для справки." << std::endl;
            clearInput();
        }
    }

    std::cout << std::endl << "========================================" << std::endl;
    std::cout << "Программа управления окном завершена." << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}