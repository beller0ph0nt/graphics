#include "Image.h"

namespace stb
{
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
}

Image::Image(fs::path&& filePath)
{
	m_data = stb::stbi_load(filePath.generic_string().c_str(), &m_width,
							&m_height, &m_channels, 0);
}

Image::Image(Image&& image)
{
	Image::operator=(move(image));
}

void Image::operator=(Image&& image)
{
	m_width = image.m_width;
	m_height = image.m_height;
	m_channels = image.m_channels;
	m_data = image.m_data;
	image.m_data = nullptr;
}

Image::~Image()
{
	stb::stbi_image_free(m_data);
}