#include <stdint.h>
#include <stdio.h>

int main() {

	int32_t a, b, c;
	a = 0xFFFFFFFF;
	b = 32;
	c = -32;

	printf("a: %#08X\tb: %#08X\tc: %#08X\n", a, b, c);

	printf("a: %#08X\tb: %#08X\tc: %#08X\n", a >> 4, b >> 4, c >> 4);

	printf("a: %#08X\tb: %#08X\tc: %#08X\n", ((uint32_t) a) >> 4, ((uint32_t) b) >> 4, ((uint32_t) c) >> 4);

}
