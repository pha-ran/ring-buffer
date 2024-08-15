#include "ring_buffer.h"
#include <stdio.h>
#include <stdlib.h>

int wmain(void)
{
	srand(20240816);

	ring_buffer rb;
	int index = 0;
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA987654";
		
	printf(str);

	for (;;)
	{
		int size1 = rand() % 120 + 1;

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

		int size2 = rand() % 120 + 1;

		if (rb.use_size() >= size2)
		{
			char buf[120] {};
			rb.dequeue(buf, size2);
			printf(buf);
		}
	}

	return 0;
}
