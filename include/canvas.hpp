#pragma once

#include "color.hpp"

class ConsoleOrigin {
  public:
    int Row;
    int Col;

    ConsoleOrigin(int r = 1, int c = 1);
    void Set(int r, int c);
};

class CanvasCell {
  public:
    Color BG;
    Color FG;

    CanvasCell();
};

class Canvas {
  private:
    CanvasCell **Cnv;
    int Width;
    int Height;
    bool rendering;

    void Init();

  public:
    ConsoleOrigin Origin;

    Canvas(int w, int h);
    ~Canvas();
    void Render();
    void PutPixel(int x, int y, Color c);
};