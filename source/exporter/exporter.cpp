/*#include "exporter.hpp"
#include "bmp.hpp"
#include "bmpconverter.hpp"

void Export(std::vector<Paint::Pixel> board, int width, int height)
{
    BMP out(width, height, true);
    for (size_t i = 0; i < board.size(); i++){
        out.set_pixel(board[i].x, height - board[i].y, board[i].b, board[i].g, board[i].r, 255);
    }
    out.write("paintout.bmp");
    
    lodepng::save_file(ConvertFile("paitout.bmp"), "outfile.png");
}*/