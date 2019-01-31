#pragma once

class Color {
  public:
    unsigned char R, G, B;

    Color(unsigned char r, unsigned char g, unsigned char b);
    Color();
    int Encode();
};
