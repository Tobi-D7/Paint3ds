#pragma once
#include "renderd7.hpp"

namespace Paint
{
    struct Pixel
    {
        bool drawn = false;
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
        void SetScale(int scale);
        int D_VectorSize(){ return (int)this->board.size(); }
        void Export();
        inline std::vector<Pixel> GetBoard() { return this->board; }
        private:
        int scale = 1;
        bool ce = true;
        int w, h;
        std::vector<Pixel> board;
    };
}
