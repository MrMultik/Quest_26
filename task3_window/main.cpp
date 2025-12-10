#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "window.h"

void showHelp() {
    std::cout << std::endl << "=== Управление системой окон ===" << std::endl;
    std::cout << "Доступные команды:" << std::endl;
    std::cout << "  create           - создать новое окно" << std::endl;
    std::cout << "  select <n>       - выбрать окно для управления" << std::endl;
    std::cout << "  move <dx> <dy>   - переместить текущее окно" << std::endl;
    std::cout << "  resize <w> <h>   - изменить размер текущего окна" << std::endl;
    std::cout << "  display          - показать экран с текущим окном" << std::endl;
    std::cout << "  info             - показать информацию о текущем окне" << std::endl;
    std::cout << "  list             - список всех окон" << std::endl;
    std::cout << "  help             - показать эту справку" << std::endl;
    std::cout << "  close            - закрыть текущее окно" << std::endl;
    std::cout << "  exit             - выход из программы" << std::endl;
    std::cout << "==================================" << std::endl << std::endl;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем разные экраны
    Screen mainScreen(80, 50);           // Основной экран
    Screen secondaryScreen(100, 60);     // Второй экран большего размера
    Screen smallScreen(40, 30);          // Маленький экран

    // Создаем вектор окон на разных экранах
    std::vector<Window> windows;
    windows.push_back(Window(mainScreen, 20, 10, 40, 20));     // Окно на основном экране
    windows.push_back(Window(secondaryScreen, 30, 20, 50, 30)); // Окно на втором экране
    windows.push_back(Window(smallScreen, 5, 5, 20, 15));      // Окно на маленьком экране

    int currentWindowIndex = 0;
    std::string command;

    std::cout << "=== Система управления несколькими окнами ===" << std::endl;
    std::cout << "Создано " << windows.size() << " окна на разных экранах" << std::endl;
    std::cout << "Текущее окно: #" << currentWindowIndex + 1 << std::endl;
    showHelp();

    while (true) {
        std::cout << std::endl << "[" << currentWindowIndex + 1 << "]> ";
        std::cin >> command;

        if (command == "create") {
            // Создание нового окна на случайном экране
            Screen newScreen(60 + rand() % 41, 40 + rand() % 31);
            Window newWindow(newScreen,
                rand() % (newScreen.getWidth() / 2),
                rand() % (newScreen.getHeight() / 2),
                20 + rand() % 31,
                10 + rand() % 21);

            windows.push_back(newWindow);
            currentWindowIndex = windows.size() - 1;
            std::cout << "Создано новое окно #" << windows.size()
                << " на экране " << newScreen.getWidth()
                << "x" << newScreen.getHeight() << std::endl;
            clearInput();
        }
        else if (command == "select") {
            int index;
            if (std::cin >> index) {
                if (index >= 1 && index <= windows.size()) {
                    currentWindowIndex = index - 1;
                    std::cout << "Выбрано окно #" << index << std::endl;
                }
                else {
                    std::cout << "Неверный номер окна. Доступно: 1-"
                        << windows.size() << std::endl;
                }
            }
            clearInput();
        }
        else if (command == "move") {
            int dx, dy;
            if (std::cin >> dx >> dy) {
                windows[currentWindowIndex].move(dx, dy);
                clearInput();
            }
            else {
                std::cout << "Неверные параметры!" << std::endl;
                clearInput();
            }
        }
        else if (command == "resize") {
            int width, height;
            if (std::cin >> width >> height) {
                windows[currentWindowIndex].resize(width, height);
                clearInput();
            }
            else {
                std::cout << "Неверные параметры!" << std::endl;
                clearInput();
            }
        }
        else if (command == "display") {
            windows[currentWindowIndex].display();
            clearInput();
        }
        else if (command == "info") {
            windows[currentWindowIndex].getInfo();
            clearInput();
        }
        else if (command == "list") {
            std::cout << std::endl << "=== Список окон ===" << std::endl;
            for (size_t i = 0; i < windows.size(); ++i) {
                const Screen& screen = windows[i].getScreen();
                std::cout << i + 1 << ". ";
                if (i == currentWindowIndex) std::cout << "[текущее] ";
                std::cout << "Экран: " << screen.getWidth() << "x"
                    << screen.getHeight();
                if (!windows[i].isWindowOpen()) std::cout << " (закрыто)";
                std::cout << std::endl;
            }
            std::cout << "=====================" << std::endl;
            clearInput();
        }
        else if (command == "help") {
            showHelp();
            clearInput();
        }
        else if (command == "close") {
            windows[currentWindowIndex].close();
            clearInput();
        }
        else if (command == "exit") {
            std::cout << "Выход из программы..." << std::endl;
            break;
        }
        else {
            std::cout << "Неизвестная команда. Введите 'help' для справки." << std::endl;
            clearInput();
        }
    }

    return 0;
}