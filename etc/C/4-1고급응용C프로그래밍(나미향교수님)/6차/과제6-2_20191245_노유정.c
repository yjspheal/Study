#include <stdio.h>

int main(void) {
	int total = 0; int input = 0; int a = 0;
	printf("Enter your numbers: <EOF> to stop.\n");
	while (scanf("%d", &input) != EOF) {
		total += input;
		printf("Total:%4d\n", total);
	}
	printf("\n\n*** End of Program ***\n");
}