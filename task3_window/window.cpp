#include "window.h"
#include <iostream>

// Конструктор по умолчанию
Window::Window() : screen(Screen()), x(10), y(10), width(30), height(15), isOpen(true) {
    ensureBoundaries();
}

// Конструктор с координатами и размерами
Window::Window(int x, int y, int width, int height)
    : screen(Screen()), x(x), y(y), width(width), height(height), isOpen(true) {
    ensureBoundaries();
}

// Конструктор с указанием экрана
Window::Window(Screen screen, int x, int y, int width, int height)
    : screen(screen), x(x), y(y), width(width), height(height), isOpen(true) {
    ensureBoundaries();
}

void Window::ensureBoundaries() {
    // Проверяем и корректируем координаты
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= screen.getWidth()) x = screen.getWidth() - 1;
    if (y >= screen.getHeight()) y = screen.getHeight() - 1;

    // Проверяем и корректируем размеры
    if (width < 1) width = 1;
    if (height < 1) height = 1;

    // Убеждаемся, что окно не выходит за границы экрана
    if (x + width > screen.getWidth()) {
        width = screen.getWidth() - x;
    }
    if (y + height > screen.getHeight()) {
        height = screen.getHeight() - y;
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

    // Делегируем отображение экрану
    screen.display(x, y, width, height);
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
    std::cout << "Экран: " << screen.getWidth() << "x" << screen.getHeight() << std::endl;
    std::cout << "===========================" << std::endl << std::endl;
}