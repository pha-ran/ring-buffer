#include "ring_buffer.h"
#include "string.h"

#pragma warning(disable:26495)

ring_buffer::ring_buffer(void) noexcept
	: _free(_size), _front(0), _back(0)
{
	;
}

ring_buffer::~ring_buffer(void) noexcept
{
	;
}

int ring_buffer::enqueue(const char* ptr, int size) noexcept
{
	if (_free < size) return -1;

	return -1;
}

int ring_buffer::dequque(const char* ptr, int size) noexcept
{
	peek(ptr, size);

	return -1;
}

int ring_buffer::peek(const char* ptr, int size) noexcept
{
	if (use_size() < size) return -1;

	return -1;
}
