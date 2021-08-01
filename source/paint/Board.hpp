#pragma once
#include "renderd7.hpp"

namespace Paint
{
    class Board
    {
        public:
        Board(int w, int h, bool centered = true);
        ~Board();
        private:
        struct Pixel
        {
            int x,
            iny y,
            u8 r,
            u8 g,
            u8 b
        };
        std::vector<Pixel> buard;
    };
}
