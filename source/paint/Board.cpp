#include "Board.hpp"
#include "exporter.hpp"
#include "bmp.hpp"

Paint::Pixel px;
RenderD7::Image tex;

Paint::Board::Board(int w, int h, bool centered)
{
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            px = {false, x, y, (u8)x, (u8)y, (u8)y};
            this->board.push_back(px);
        }
    }
    this->w = w;
    this->h = h;
}

Paint::Board::~Board(){}

void Paint::Board::Draw()
{
    RenderD7::OnScreen(Bottom);
    BMP out(w, h, true);
    for (size_t i = 0; i < board.size(); i++){
        out.set_pixel(board[i].x, h - board[i].y, board[i].b, board[i].g, board[i].r, 255);
    }
    out.write("paintout.bmp");
    std::vector<unsigned char> bmpbuff;
    lodepng::load_file(bmpbuff, "paintout.bmp");
    unsigned w, h;
    std::vector<unsigned char> ImageBuff;
    decodeBMP(ImageBuff, w, h, bmpbuff);
    std::vector<unsigned char> png;
    lodepng::encode(png, ImageBuff, w, h);
    
    tex.LoadPFromBuffer(png);
    tex.Draw(0, 0);
    tex.Unload();
}

void Paint::Board::DrawDot(int x, int y)
{
	//Paint::Pixel newpx = {x * this->scale, y * this->scale, 255, 255, 255};
	//this->board.push_back(newpx);
        Paint::Pixel pxn;
        for (int j = x; j < x + this->scale; j++)
        {
           for (int k = y; k < y + this->scale; k++)
           {
               pxn = {false, j, k, 255, 255, 255};
               this->board.push_back(pxn);
           }
       }
}

void Paint::Board::SetScale(int scale)
{
	if (scale > 0)
        this->scale = scale;

    else this->scale = 1;
}
