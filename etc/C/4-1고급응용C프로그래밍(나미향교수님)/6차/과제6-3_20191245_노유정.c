#include <stdio.h>

int calGCD(int a, int b);
int main(void) {
	int n1, n2;
	printf("두 개의 정수를 입력하시오 : ");
	scanf("%d %d", &n1, &n2);
	printf("GCD is %d\n", calGCD(n1, n2));
}
int calGCD(int a, int b) {
	int r = 0, r1;
	if (a < b) {
		r = a; a = b; b = r;
	}
	r = a % b;
	while (r != 0) {
		r1 = b % r;
		b = r; r = r1;
	}
	return b;
}