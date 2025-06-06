#include <stdio.h>
int main(void) {
	float b = 3.141592;
	int a = 1000;

	printf("a:%7d, c:%-13s,   b:%f\n", a, "C-language", b);
	printf("a:%d,    c:%15s, b:%+8.4f\n", a, "C-language", b);
	printf("a:%-7d, c:%s,      b:%8.3f\n", a, "C-language", b);
}