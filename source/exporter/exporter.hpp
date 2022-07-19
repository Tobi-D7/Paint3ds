#pragma once
// Formats
#include "Board.hpp"

unsigned decodeBMP(std::vector<unsigned char>& image, unsigned& w, unsigned& h, const std::vector<unsigned char>& bmp);
void Export(std::vector<Paint::Pixel> board, int width, int height);
