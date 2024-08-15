#include "ring_buffer.h"
#include <stdio.h>

int wmain(void)
{
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";

	ring_buffer rb;

	if (rb.enqueue(str, 50) < 0) /*__debugbreak()*/;
	if (rb.peek(str, 50) < 0) /*__debugbreak()*/;

	return 0;
}
