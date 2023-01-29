#include "Image.h"
#include <iostream>

namespace jf
{
	Image::Image()
	{
		m_image = new GLFWimage;
		m_data = nullptr;
	}

	Image::~Image()
	{
		stbi_image_free(m_data);
		delete m_image;
	}

	void Image::loadFromFile(const std::string file_path)
	{
		int width, height, channels_in_file;
		m_data = stbi_load(file_path.c_str(), &width, &height, &channels_in_file, 0);
		std::cout << channels_in_file << std::endl;
		if (!m_data)
			std::cout << "Image failed to load: " << file_path << std::endl;

		m_image->pixels = m_data;
		m_image->width = width;
		m_image->height = height;
	}

	GLFWimage* Image::getImage() const
	{
		return m_image;
	}
}