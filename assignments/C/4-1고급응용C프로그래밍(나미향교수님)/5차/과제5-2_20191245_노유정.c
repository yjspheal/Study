#include <stdio.h>

int main(void) {
	int score;
	printf("Enter the score(0-100):");
	scanf("%d", &score);

	int point = (score - 50) / 10;
	if (score == 100);
		point = 4;

	switch(point) {
		case 4:
			printf("The grade is A\n");
			break;
		case 3:
			printf("The grade is B\n");
			break;
		case 2:
			printf("The grade is C\n");
			break;
		case 1:
			printf("The grade is D\n");
			break;
		default:
			printf("The grade is F\n");
			break;
	}
}