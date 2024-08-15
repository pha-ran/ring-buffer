#include "ring_buffer.h"
#include <stdio.h>

int wmain(void)
{
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";

	ring_buffer rb;
	rb.print();

	if (rb.enqueue(str, 5) < 0) __debugbreak();
	rb.print();

	if (rb.enqueue(str + 5, 4) < 0) __debugbreak();
	rb.print();

	if (rb.enqueue(str + 9, 1) < 0) __debugbreak();
	rb.print();

	return 0;
}
