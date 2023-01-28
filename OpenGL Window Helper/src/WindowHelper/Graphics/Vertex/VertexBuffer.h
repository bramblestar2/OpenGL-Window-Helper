#pragma once
#include <iostream>
#include <GL/glew.h>

namespace jf
{
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, unsigned int size);
		VertexBuffer();

		~VertexBuffer() {
			if (ID)
				glDeleteBuffers(1, ID.get());
		}

		void bind();
		void unbind();


		VertexBuffer& operator=(VertexBuffer&& other);
	private:
		std::unique_ptr<unsigned int> ID;
	};
}