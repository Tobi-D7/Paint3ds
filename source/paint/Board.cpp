#include "Board.hpp"

Paint::Pixel px;

Paint::Board::Board(int w, int h, bool centered)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            px = {x, y, 255, 255, 255};
            this->board.push_back()
        }
    }
}

Paint::Board::~Board(){}

void Paint::Board::Draw()
{
    for (int i = 0; i < this->board.size(); i++)
    {
        RenderD7::DrawPx(this->board[i].x(), this->board[i].y(), C2D_Color32(this->board[i].r(), this->board[i].g(), this->board[i].b(), 255));
    }
}
