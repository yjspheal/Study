#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int nums[] = { 1, 3, 5, 7, 21, 22, 24, 25, 49, 51 };
	int i; int n;
	bool b = false;

	printf("In array : 1 3 5 7 21 22 24 25 49 51\n");
	printf("Input : ");
	scanf("%d", &n);
	for (i = 0; i < 10; i++) {
		if (nums[i] == n) {
			b = true;
		}
	}
	printf("Result : ");
	if (b == true) {
		printf("exists\n");
	}
	else {
		printf("not exists\n");
	}
}