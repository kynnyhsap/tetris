#include "canvas.hpp"
#include <iostream>

ConsoleOrigin::ConsoleOrigin(int r, int c) {
    Row = 1;
    Col = 1;

    Set(r, c);
}

void ConsoleOrigin::Set(int r, int c) {
    if (r >= 1)
        Row = r;

    if (c >= 1)
        Col = c;
}

CanvasCell::CanvasCell() {
    BG = Color(0, 0, 0);
    FG = Color(225, 225, 225);
}

Canvas::Canvas(int w, int h) {
    Width = w;
    Height = h;

    Init();

    Origin = ConsoleOrigin();
}

Canvas::~Canvas() {
    for (int i = 0; i < Height; ++i) {
        delete[] Cnv[i];
    }

    delete[] Cnv;
}

void Canvas::Init() {
    Cnv = new CanvasCell *[Height];
    for (int i = 0; i < Height; i++) {
        Cnv[i] = new CanvasCell[Width];

        // init values
        for (int j = 0; j < Width; j++) {
            Cnv[i][j].BG = Color(0, 0, 0);
            Cnv[i][j].FG = Color(225, 225, 225);
        }
    }
}

void Canvas::Render() {
    for (int yi = 0; yi < Height / 2; yi++) {
        // set cursor position
        std::cout << "\033[" << Origin.Row + yi << ";" << Origin.Col << "H";

        for (int xi = 0; xi < Width; xi++) {
            int encoded1 = Cnv[yi * 2][xi].BG.Encode();
            int encoded2 = Cnv[yi * 2 + 1][xi].BG.Encode();
            // std::cout << encoded << std::endl;
            std::cout << "\033[38;5;" << encoded1 << "m";
            std::cout << "\033[48;5;" << encoded2 << "m";
            std::cout << "\xE2\x96\x80";      // u just need this line -_-
            std::cout << "\033[" << 0 << "m"; // reseting
        }

        std::cout << "\n";
    }
}

void Canvas::PutPixel(int x, int y, Color c) { Cnv[y][x].BG = c; }
