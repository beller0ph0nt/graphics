#include "Image.h"

namespace stb
{
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
}

Image::Image(fs::path&& filePath)
{}

Image::Image(Image&& image)
{}

void Image::operator=(Image&& image)
{}

Image::~Image()
{}