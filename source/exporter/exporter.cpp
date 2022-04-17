#include "exporter.hpp"


#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void Export(std::vector<Paint::Pixel> board, int width, int height)
{
    uint8_t* buffer = new uint8_t[width * height * 4];
    for (size_t i = 0; i < board.size(); i++){
        size_t index = 4 * (board[i].y * width + board[i].x);
        buffer[index + 0] = ((int)board[i].r);
        buffer[index + 1] = ((int)board[i].g);
        buffer[index + 2] = ((int)board[i].b);
        buffer[index + 3] = ((int)255);
    }
    stbi_write_bmp("sdmc:/file.bmp", width, height, 3, buffer);
    //stbi_write_jpg("sdmc:/file.jpg", width, height, 3, buffer, 95);
}