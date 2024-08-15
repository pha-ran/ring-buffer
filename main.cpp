#include "ring_buffer.h"
#include <stdio.h>

int wmain(void)
{
	const char* str =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"\
		"zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210";

	ring_buffer rb;
	rb.print();
	printf("\n");

	if (rb.enqueue(str, 10) < 0) __debugbreak();
	rb.print();
	printf("\n");

	char buf[8] {};

	if (rb.peek(buf, 7) < 0) __debugbreak();
	rb.print();
	printf(" | %s\n", buf);

	if (rb.dequeue(buf, 7) < 0) __debugbreak();
	rb.print();

	return 0;
}
