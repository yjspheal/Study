#include <stdio.h>
#include <string.h>

int main(void) {
	int i, temp;
	char strn[50] = {0}, nrts[50];
	int n;
	char s;

	printf("Input : ");
	
	for (i = 0; i < 50; i++) {
		scanf("%c", &s);
		n = (int)"\n";
		if (s == n) {
			break;
		}
		strn[i] = s;
	}
	printf("Result : ");
	for (i = 0; i < 50; i++) {
		if (strn[i] == 0) {
			continue;
		}
		printf(strn[49 - i]);
	}
	printf("\n");
}