#include <stdio.h>
int main(void)
{
	float rad;
	int deg;
	printf("Enter an angle in degrees: ");
	scanf("%d", &deg);
	rad = deg / 57.295779;
	printf("%d degrees is %.6f radians", deg, rad);
	return 0;
}
