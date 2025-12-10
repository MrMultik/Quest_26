#include "screen.h"
#include <iostream>
#include <iomanip>

Screen::Screen(int w, int h) : width(w), height(h) {
    if (w <= 0) width = 80;
    if (h <= 0) height = 50;
}

int Screen::getWidth() const {
    return width;
}

int Screen::getHeight() const {
    return height;
}

bool Screen::isValidPosition(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool Screen::isValidSize(int w, int h) const {
    return w > 0 && h > 0 && w <= width && h <= height;
}

void Screen::display(int windowX, int windowY, int windowWidth, int windowHeight) const {
    std::cout << std::endl << "=== Экран " << width << "x" << height << " ===" << std::endl;
    std::cout << "Окно: позиция(" << windowX << "," << windowY
        << ") размер(" << windowWidth << "x" << windowHeight << ")"
        << std::endl << std::endl;

    // Верхняя граница с координатами
    std::cout << "  ";
    for (int i = 0; i < width; ++i) {
        if (i % 10 == 0) {
            std::cout << i / 10;
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl << "  ";
    for (int i = 0; i < width; ++i) {
        std::cout << i % 10;
    }
    std::cout << std::endl;

    // Отображаем экран (только первые 25 строк для наглядности)
    int displayRows = 25;
    if (displayRows > height) displayRows = height;

    for (int row = 0; row < displayRows; ++row) {
        // Номер строки
        std::cout << std::setw(2) << std::setfill(' ') << row << " ";

        for (int col = 0; col < width; ++col) {
            // Проверяем, находится ли точка внутри окна
            bool isInsideWindow = (col >= windowX && col < windowX + windowWidth &&
                row >= windowY && row < windowY + windowHeight);

            std::cout << (isInsideWindow ? "1" : "0");
        }
        std::cout << std::endl;

        // Если окно начинается после 25 строки, показываем только начало
        if (row == 24 && displayRows < height) {
            std::cout << "... (показано 25 из " << height << " строк)" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}