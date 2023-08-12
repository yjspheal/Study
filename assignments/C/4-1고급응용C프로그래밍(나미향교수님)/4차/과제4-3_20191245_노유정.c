#include <stdio.h>
void Celsius(void);
void Fahrenheit(void);
int main(void)
{
	Celsius();
	printf("\n");
	Fahrenheit();
}
float Get_Celsius(void);
float Celsius_to_Fahrenheit(float celsi);
void Print_Fahrenheit(float fahre);
void Celsius(void) {
	float cel, fah;
	cel = Get_Celsius();
	fah = Celsius_to_Fahrenheit(cel);
	Print_Fahrenheit(fah);
}
float Get_Celsius(void) {
	float c;
	printf("섭씨 온도를 입력하시오 : ");
	scanf("%f", &c);
	return c;
}
float Celsius_to_Fahrenheit(float celsi) {
	return celsi * 180. / 100 + 32;
}
void Print_Fahrenheit(float fahre) {
	printf("화씨 온도는 %.2f 입니다\n", fahre);
}
float Get_Fahrenheit(void);
float Fahrenheit_to_Celsius(float fahre);
void Print_Celsius(float celsi);
void Fahrenheit(void) {
	float cel, fah;
	fah = Get_Fahrenheit();
	cel = Fahrenheit_to_Celsius(fah);
	Print_Celsius(cel);
}
float Get_Fahrenheit(void) {
	float f;
	printf("화씨 온도를 입력하시오 : ");
	scanf("%f", &f);
	return f;
}
float Fahrenheit_to_Celsius(float fahre) {
	return 100./180 * (fahre - 32);
}
void Print_Celsius(float celsi) {
	printf("섭씨 온도는 %.2f 입니다\n", celsi);
}
