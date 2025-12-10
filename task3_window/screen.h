#pragma once
#include <vector>

class Screen {
private:
    int width;
    int height;

public:
    // Конструктор с параметрами
    Screen(int w = 80, int h = 50);

    // Геттеры
    int getWidth() const;
    int getHeight() const;

    // Проверки
    bool isValidPosition(int x, int y) const;
    bool isValidSize(int width, int height) const;

    // Метод для отображения экрана с окном
    void display(int windowX, int windowY, int windowWidth, int windowHeight) const;
};