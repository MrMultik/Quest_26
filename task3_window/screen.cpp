#include "screen.h"

bool Screen::isValidPosition(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool Screen::isValidSize(int width, int height) {
    return width > 0 && height > 0 &&
        width <= WIDTH && height <= HEIGHT;
}