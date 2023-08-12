#include <stdio.h>

int main(void) {
	int target; int i, k;
	printf("Enter number of rows : ");
	scanf("%d", &target);
	for (i = 1; i <= target; i++) {
		for (k = 0; k < target-i; k++) {
			printf(" ");
		}
		for (k = 0; k < i*2-1; k++) {
			printf("*");
		}
	printf("\n");
	}
}