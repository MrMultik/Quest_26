#pragma once

class Screen {
public:
    static const int WIDTH = 80;
    static const int HEIGHT = 50;

    static bool isValidPosition(int x, int y);
    static bool isValidSize(int width, int height);
};