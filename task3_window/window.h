#pragma once
#include "screen.h"
#include <string>

class Window {
private:
    int x;      // координата X левого верхнего угла
    int y;      // координата Y левого верхнего угла
    int width;  // ширина окна
    int height; // высота окна
    bool isOpen; // открыто ли окно

    void ensureBoundaries();

public:
    Window();
    Window(int x, int y, int width, int height);

    void move(int dx, int dy);
    void resize(int newWidth, int newHeight);
    void display() const;
    void close();

    bool isWindowOpen() const { return isOpen; }
    void getInfo() const;
};