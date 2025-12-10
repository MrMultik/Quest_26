#pragma once
#include "screen.h"

class Window {
private:
    Screen screen;      // Экран, на котором расположено окно
    int x;              // координата X левого верхнего угла
    int y;              // координата Y левого верхнего угла
    int width;          // ширина окна
    int height;         // высота окна
    bool isOpen;        // открыто ли окно

    void ensureBoundaries();

public:
    // Конструкторы
    Window();
    Window(int x, int y, int width, int height);
    Window(Screen screen, int x, int y, int width, int height);

    // Методы управления окном
    void move(int dx, int dy);
    void resize(int newWidth, int newHeight);
    void display() const;
    void close();

    // Геттеры
    bool isWindowOpen() const { return isOpen; }
    const Screen& getScreen() const { return screen; }

    // Информация
    void getInfo() const;
};