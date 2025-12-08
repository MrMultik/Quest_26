#include <iostream>
#include <string>
#include "player.h"

void showHelp() {
    std::cout << "\n=== Аудиоплеер ===\n";
    std::cout << "Доступные команды:\n";
    std::cout << "  play <название>   - воспроизвести трек\n";
    std::cout << "  pause             - поставить на паузу\n";
    std::cout << "  next              - следующий трек (случайный)\n";
    std::cout << "  stop              - остановить воспроизведение\n";
    std::cout << "  list              - показать все треки\n";
    std::cout << "  help              - показать эту справку\n";
    std::cout << "  exit              - выход из программы\n";
    std::cout << "===================\n\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    Player player;
    std::string command;

    std::cout << "=== Добро пожаловать в аудиоплеер! ===\n";
    showHelp();

    while (true) {
        std::cout << "\n> ";
        std::cin >> command;

        if (command == "play") {
            std::string trackName;
            std::getline(std::cin >> std::ws, trackName);
            player.play(trackName);
        }
        else if (command == "pause") {
            player.pause();
        }
        else if (command == "next") {
            player.next();
        }
        else if (command == "stop") {
            player.stop();
        }
        else if (command == "list") {
            player.listTracks();
        }
        else if (command == "help") {
            showHelp();
        }
        else if (command == "exit") {
            std::cout << "Выход из программы...\n";
            break;
        }
        else {
            std::cout << "Неизвестная команда. Введите 'help' для справки.\n";
        }
    }

    return 0;
}