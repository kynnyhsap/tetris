#include "canvas.hpp"
#include "color.hpp"
#include <iostream>

int main() {
    Canvas cv = Canvas(20, 10);
    cv.Origin.Set(10, 20);

    for (int i = 0; i < 10; i++) {
        cv.PutPixel(i, i, Color(225, 0, 0));
        cv.PutPixel(i + 10, i, Color(225, 0, 0));
    }

    system("clear");
    cv.Render();

    std::cout << "Hello, World! =)" << std::endl;
    return 0;
}