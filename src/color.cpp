#include "color.hpp"

Color::Color(unsigned char r, unsigned char g, unsigned char b) {
    R = r;
    G = g;
    B = b;
}

Color::Color() {
    R = 0;
    G = 0;
    B = 0;
}

int Color::Encode() {
    R /= 51;
    G /= 51;
    B /= 51;

    return 16 + 36 * R + 6 * G + B;
}
