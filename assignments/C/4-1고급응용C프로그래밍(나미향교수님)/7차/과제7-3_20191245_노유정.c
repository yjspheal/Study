#include <stdio.h>

#define row 5
#define col 6

void rowAverage(int table[][col], float rowAve[]);
int main(void) {
	int tb[row][col] = { 0 };
	float avg[row] = { 0 };
	int p,q;

	for (p = 0; p < row; p++) {
		for (q = 0; q < col; q++) {
			tb[p][q] = p * 3 + q + 1;
		}
	}

	rowAverage(tb, avg);

	for (p = 0; p < row; p++) {
		for (q = 0; q < col; q++) {
			printf("%3d", tb[p][q]);
		}
		printf("  | %5.2f\n", avg[p]);
	}
}
void rowAverage(int table[][col], float rowAve[]) {
	int p, q , sum;

	for (p = 0; p < 5; p++) {
		sum = 0;
		for (q = 0; q < col; q++) {
			sum += table[p][q];
		}
		rowAve[p] = sum * 1.0 / col;
	}
}