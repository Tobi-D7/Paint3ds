#include "Board.hpp"

Paint::Pixel px;

Paint::Board::Board(int w, int h, bool centered)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            px = {x, y, x, y, y};
            this->board.push_back(px);
        }
    }
}

Paint::Board::~Board(){}

void Paint::Board::Draw()
{
    for (int i = 0; i < (int)this->board.size(); i++)
    {
        RenderD7::DrawPx(this->board[i].x, this->board[i].y, C2D_Color32(this->board[i].r, this->board[i].g, this->board[i].b, 255));
    }
}

void Paint::Board::DrawDot(int x, int y)
{
	Paint::Pixel newpx = {x, y, 255, 255, 255};
	this->board.push_back(newpx);
}

void Paint::Board::SetScale(int scale)
{
	if (scale > 0)
             this->scale = scale;

       else this->scale = 1;
}
