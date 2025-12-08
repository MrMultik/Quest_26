#include "window.h"
#include <iostream>
#include <string>
#include <iomanip>

Window::Window() : x(10), y(10), width(30), height(15), isOpen(true) {
    ensureBoundaries();
}

Window::Window(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height), isOpen(true) {
    ensureBoundaries();
}

void Window::ensureBoundaries() {
    // Проверяем и корректируем координаты
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= Screen::WIDTH) x = Screen::WIDTH - 1;
    if (y >= Screen::HEIGHT) y = Screen::HEIGHT - 1;

    // Проверяем и корректируем размеры
    if (width < 1) width = 1;
    if (height < 1) height = 1;

    // Убеждаемся, что окно не выходит за границы экрана
    if (x + width > Screen::WIDTH) {
        width = Screen::WIDTH - x;
    }
    if (y + height > Screen::HEIGHT) {
        height = Screen::HEIGHT - y;
    }
}

void Window::move(int dx, int dy) {
    if (!isOpen) {
        std::cout << "Окно закрыто!" << std::endl;
        return;
    }

    x += dx;
    y += dy;
    ensureBoundaries();

    std::cout << "Окно перемещено. Новые координаты: ("
        << x << ", " << y << ")" << std::endl;
}

void Window::resize(int newWidth, int newHeight) {
    if (!isOpen) {
        std::cout << "Окно закрыто!" << std::endl;
        return;
    }

    width = newWidth;
    height = newHeight;
    ensureBoundaries();

    std::cout << "Размер изменён. Новый размер: "
        << width << "x" << height << std::endl;
}

void Window::display() const {
    if (!isOpen) {
        std::cout << "Окно закрыто!" << std::endl;
        return;
    }

    std::cout << std::endl << "=== Экран " << Screen::WIDTH << "x" << Screen::HEIGHT << " ===" << std::endl;
    std::cout << "Окно: позиция(" << x << "," << y << ") размер("
        << width << "x" << height << ")" << std::endl << std::endl;

    // Верхняя граница с координатами
    std::cout << "  ";
    for (int i = 0; i < Screen::WIDTH; ++i) {
        if (i % 10 == 0) {
            std::cout << i / 10;
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl << "  ";
    for (int i = 0; i < Screen::WIDTH; ++i) {
        std::cout << i % 10;
    }
    std::cout << std::endl;

    // Отображаем экран (только первые 25 строк для наглядности)
    int displayRows = 25;
    if (displayRows > Screen::HEIGHT) displayRows = Screen::HEIGHT;

    for (int row = 0; row < displayRows; ++row) {
        // Номер строки
        std::cout << std::setw(2) << std::setfill(' ') << row << " ";

        for (int col = 0; col < Screen::WIDTH; ++col) {
            // Проверяем, находится ли точка внутри окна
            if (col >= x && col < x + width &&
                row >= y && row < y + height) {
                // Внутри окна - показываем '1'
                std::cout << "1";
            }
            else {
                // Вне окна - показываем '0'
                std::cout << "0";
            }
        }
        std::cout << std::endl;

        // Если окно начинается после 25 строки, показываем только начало
        if (row == 24 && displayRows < Screen::HEIGHT) {
            std::cout << "... (показано 25 из " << Screen::HEIGHT << " строк)" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

void Window::close() {
    if (isOpen) {
        isOpen = false;
        std::cout << "Окно закрыто." << std::endl;
    }
    else {
        std::cout << "Окно уже закрыто." << std::endl;
    }
}

void Window::getInfo() const {
    std::cout << std::endl << "=== Информация об окне ===" << std::endl;
    std::cout << "Статус: " << (isOpen ? "Открыто" : "Закрыто") << std::endl;
    std::cout << "Позиция: (" << x << ", " << y << ")" << std::endl;
    std::cout << "Размер: " << width << "x" << height << std::endl;
    std::cout << "Границы экрана: " << Screen::WIDTH << "x" << Screen::HEIGHT << std::endl;
    std::cout << "===========================" << std::endl << std::endl;
}