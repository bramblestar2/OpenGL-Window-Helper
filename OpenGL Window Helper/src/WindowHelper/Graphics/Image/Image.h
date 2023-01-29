#pragma once
#include "../../../External/stb_image/stb_image.h"
#include "../../Setup.h"
#include <string>

namespace jf
{
	class Image
	{
	public:
		Image();
		~Image();

		void loadFromFile(const std::string file_path);
		GLFWimage* getImage() const;

		GLFWimage* operator*() { return m_image; }
	private:
		GLFWimage* m_image;
		unsigned char* m_data;
	};
}