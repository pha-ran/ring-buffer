﻿#include "ring_buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wmain(void)
{
	srand(12341234);

	ring_buffer rb;
	
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"yxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543";

	char buf[121];

	int in = 0;
	int out = 0;

	for (;;)
	{
		int size1 = rand() % 120 + 1;

		/*if (rb.free_size() >= size1)
		{
			if (in + size1 > 120)
			{
				rb.enqueue(str + in, 120 - in);
				in = rb.enqueue(str, size1 - (120 - in));
			}
			else
			{
				in += rb.enqueue(str + in, size1);
				if (in >= 120) in = 0;
			}
		}*/

		if (rb.direct_enqueue_size() >= size1)
		{
			if (in + size1 > 120)
			{
				memcpy(rb.back(), str + in, 120 - in);
				rb.move_back(120 - in);

				memcpy(rb.back(), str, size1 - (120 - in));
				rb.move_back(size1 - (120 - in));
				in = size1 - (120 - in);
			}
			else
			{
				memcpy(rb.back(), str + in, size1);
				rb.move_back(size1);
				in += size1;

				if (in >= 120) in = 0;
			}
		}

		int size2 = rand() % (120 - out) + 1;

		/*if (rb.use_size() >= size2)
		{
			char cur[121]{};

			rb.peek(cur, size2);
			printf(cur);

			out += rb.dequeue(buf + out, size2);

			if (out >= 120)
			{
				out = 0;
				buf[120] = '\0';

				if (strcmp(str, buf) != 0) __debugbreak();

				memset(buf, 0, sizeof(buf));
			}
		}*/

		if (rb.direct_dequeue_size() >= size2)
		{
			char cur[121]{};

			rb.peek(cur, size2);
			printf(cur);

			memcpy(buf + out, rb.front(), size2);
			rb.move_front(size2);
			out += size2;

			if (out >= 120)
			{
				out = 0;
				buf[120] = '\0';

				if (strcmp(str, buf) != 0) __debugbreak();

				memset(buf, 0, sizeof(buf));
			}
		}
	}

	return 0;
}
