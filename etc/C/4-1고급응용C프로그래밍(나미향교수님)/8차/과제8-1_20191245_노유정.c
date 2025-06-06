#include <stdio.h>

void func(int a, int b, int* ad, int* mn, int* ml, int* dv);
int main(void) {
	int n1, n2, w = 0, x = 0, y = 0, z = 0;
	int* add = &w, * sub = &x, * mul = &y, * div = &z;
	printf("Enter two integers : ");
	scanf("%d %d", &n1, &n2);
	
	func(n1, n2, add, sub, mul, div);

	printf("%d + %d = %d\n", n1, n2, *add);
	printf("%d - %d = %d\n", n1, n2, *sub);
	printf("%d * %d = %d\n", n1, n2, *mul);
	printf("%d / %d = %d\n", n1, n2, *div);
}
void func(int a, int b, int* ad, int* sb, int* ml, int* dv) {
	*ad = a + b;
	*sb = a - b;
	*ml = a * b;
	*dv = a / b;
}
