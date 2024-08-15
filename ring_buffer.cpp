#include "ring_buffer.h"
#include <string.h>

// Test
#include <stdio.h>

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

	int direct = direct_enqueue_size();

	do
	{
		if (size <= direct)
		{
			memcpy(_data + _back, ptr, size);
			_back = remain(_back + size);

			break;
		}

		memcpy(_data + _back, ptr, direct);

		_back = size - direct;
		memcpy(_data, ptr + direct, _back);

	} while (0);

	_free -= size;

	return size;
}

int ring_buffer::dequeue(char* ptr, int size) noexcept
{
	if (use_size() < size) return -1;

	int direct = direct_dequeue_size();

	do
	{
		if (size <= direct)
		{
			memcpy(ptr, _data + _front, size);
			_front = remain(_front + size);

			break;
		}

		memcpy(ptr, _data + _front, direct);

		_front = size - direct;
		memcpy(ptr + direct, _data, _front);

	} while (0);

	_free += size;

	return size;
}

int ring_buffer::peek(char* ptr, int size) noexcept
{
	if (use_size() < size) return -1;

	int direct = direct_dequeue_size();

	do
	{
		if (size <= direct)
		{
			memcpy(ptr, _data + _front, size);

			break;
		}

		memcpy(ptr, _data + _front, direct);
		memcpy(ptr + direct, _data, size - direct);

	} while (0);

	return size;
}

// Test
void ring_buffer::print(void) const noexcept
{
	printf("use %d | free %d | size %d | front %d | back %d | ", use_size(), free_size(), _size, _front, _back);
	printf("direct_enqueue_size %d | direct_dequeue_size %d | ", direct_enqueue_size(), direct_dequeue_size());

	for (int count = 0; count < use_size(); ++count)
		printf("%c", _data[remain(_front + count)]);
}
