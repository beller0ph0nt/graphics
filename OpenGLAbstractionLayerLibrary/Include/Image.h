#pragma once

#include <experimental\filesystem>

namespace fs = std::experimental::filesystem;

class Image {
public:
	Image(fs::path&& filePath);

	Image(Image&& image);
	void operator=(Image&& image);

	Image(const Image& image) = delete;
	void operator=(const Image& image) = delete;
	
	~Image();
private:
	int m_width;
	int m_height;
	int m_channels;
	unsigned char* m_data;
};