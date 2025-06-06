#include <stdio.h>
#include <stdlib.h>

int* reverse_array(int* original, int length);
int main(void) {
	int ary[21] = { 0 };
	int i,j;

	printf("Enter a sequence of positive integers.\n");
	for (i = 0; i <= 21; i++) {
		scanf("%d", &ary[i]);
		if (ary[i] <= 0) {
			i--;
			break;
		}
	}
	
	for (j = 0; j <= i; j++) {
		printf("%d ", reverse_array(ary, i)[j]);
	}
	printf("\n");
	return 0;
}
int* reverse_array(int* original, int length) {
	int* array = (int*)malloc(sizeof(int) * length);
	int i;

	for (i = 0; i <= length; i++) {
		array[i] = original[length - i];
	}
	return array;
	free(array);
}