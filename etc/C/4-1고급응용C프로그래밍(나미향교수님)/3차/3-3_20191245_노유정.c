#include <stdio.h>

int main(void)
{
	float fah;
	float cels;
	printf("Enter the temperature in Fahrenheit: ");
	scanf("%f", &fah);
	cels = (100./180)*(fah-32);
	printf("Fahrenheit temperature is: %.1f\n", fah);
	printf("Celsius temperature is: %.1f", cels);
	return 0;
}