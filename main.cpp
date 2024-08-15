#include "ring_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int wmain(void)
{
	srand(20240815);

	ring_buffer rb;
	int index = 0;
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA987654";
		
	srand(20240815);
	printf(str);

	for (;;)
	{
		int size1 = rand() % ring_buffer::_size;

		if (rb.free_size() >= size1)
		{
			if (index + size1 > 120)
			{
				rb.enqueue(str + index, 120 - index);
				index = rb.enqueue(str, size1 - (120 - index));
			}
			else
				index += rb.enqueue(str + index, size1);
		}

		int size2 = rand() % ring_buffer::_size;

		if (rb.use_size() >= size2)
		{
			char buf[120] {};
			rb.dequeue(buf, size2);
			printf(buf);
		}
	}

	return 0;
}
