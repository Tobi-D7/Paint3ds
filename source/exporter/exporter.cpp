#include "exporter.hpp"


#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void Export(std::vector<Paint::Pixel> board, int width, int height)
{
    uint8_t* buffer = new uint8_t[width * height * 4];
    int index = 0;
    for (size_t i = 0; i < board.size(); i++){
        buffer[index++] = ((int)board[i].r);
        buffer[index++] = ((int)board[i].g);
        buffer[index++] = ((int)board[i].b);
        buffer[index++] = ((int)255);
    }
    stbi_write_bmp("sdmc:/file.bmp", width, height, 3, buffer);
    //stbi_write_jpg("sdmc:/file.jpg", width, height, 3, buffer, 95);
}