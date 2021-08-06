#pragma once
#include "renderd7.hpp"

namespace Paint
{
    struct Pixel
    {
        int x;
        int y;
        u8 r;
        u8 g;
        u8 b;
    };
    class Board
    {
        public:
        Board(int w, int h, bool centered = true);
        ~Board();
        void Draw();
        void DrawDot(int x, int y);
        private:
        bool ce = true;
        std::vector<Pixel> board;
    };
}
