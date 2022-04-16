#include "exporter.hpp"


#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void Export(std::vector<Paint::Pixel> board, int width, int height)
{
    const void* buffer = NULL;
    for (size_t i = 0; i < board.size(); i++){
        size_t index = 4 * (board[i].y * width + board[i].x);
        ((uint8_t*)buffer)[index + 0] = ((uint8_t)board[i].r);
        ((uint8_t*)buffer)[index + 1] = ((uint8_t)board[i].g);
        ((uint8_t*)buffer)[index + 2] = ((uint8_t)board[i].b);
        ((uint8_t*)buffer)[index + 3] = ((uint8_t)255);
    }
    stbi_write_bmp("sdmc:/file.bmp", width, height, 3, buffer);
}