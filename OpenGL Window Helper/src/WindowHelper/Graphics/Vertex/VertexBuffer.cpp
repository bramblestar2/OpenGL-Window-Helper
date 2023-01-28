#include "VertexBuffer.h"

namespace jf
{
	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		glGenBuffers(1, &*ID.get());
		glBindBuffer(GL_ARRAY_BUFFER, *ID.get());
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	VertexBuffer::VertexBuffer()
	{
	}

	void VertexBuffer::bind() {
		glBindBuffer(GL_ARRAY_BUFFER, *ID.get());
	}

	void VertexBuffer::unbind() {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other)
	{
		ID = std::move(other.ID);
		return *this;
	}
}