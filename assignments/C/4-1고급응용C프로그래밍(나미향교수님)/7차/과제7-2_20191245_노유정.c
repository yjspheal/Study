#include <stdio.h>

int main(void) {
	int x[3][3], y[3][4];
	int z[3][4] = { 0 };
	int p, q, i;
	for (p = 0; p < 3; p++) {
		for (q = 0; q < 3; q++) {
			x[p][q] = 3 * p + q + 1;	
		}
	}

	for (p = 0; p < 3; p++) {
		for (q = 0; q < 3; q++) {
			printf("%d ", x[p][q]);
		}
		printf("\n");
	}
	printf("\n");

	for (p = 0; p < 3; p++) {
		for (q = 0; q < 4; q++) {
			y[p][q] = 3 * q + p + 1;
		}
	}

	for (p = 0; p < 3; p++) {
		for (q = 0; q < 4; q++) {
			printf("%d ", y[p][q]);
		}
		printf("\n");
	}
	printf("\n");



	for (p = 0; p < 3; p++) {
		for (q = 0; q < 4; q++) {
			for (i = 0; i < 3; i++) {
				z[p][q] += x[p][i] * y[i][q];
			}
		}
	}

	for (p = 0; p < 3; p++) {
		for (q = 0; q < 4; q++) {
			printf("%3d ", z[p][q]);
		}
	printf("\n");
	}


}