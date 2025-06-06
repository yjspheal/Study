#include <stdio.h>
int sum(int a, int b);
int min(int a, int b);
int mul(int a, int b);
float div(float a, float b);
int main(void) {
	int x, y, P, S, M;
	float D;
	printf("First num : ");
	scanf("%d", &x);
	printf("Second num : ");
	scanf("%d", &y);
	P = sum(x, y);
	S = min(x, y);
	M = mul(x, y);
	D = div(x, y);
	printf("Add : %d\n", P);
	printf("Sub : %d\n", S);
	printf("Mul : %d\n", M);
	printf("Div : %f\n", D);
}
int sum(int a, int b) {
	return a + b;
}
int min(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
float div(float a, float b) {
	return a / b;
}