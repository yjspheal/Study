#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);
int main(void) {
	int col, row, i, j, ele;
	int **ary, **newary;

	printf("Number of Rows : ");
	scanf("%d", &row);
	printf("Number of Cols : ");
	scanf("%d", &col);

	ary = (int*)malloc(sizeof(int) * row);

	for (i = 0; i < row; i++) {
		ary[i] = (int*)malloc(sizeof(int) * col);
	}

	if (ary == NULL) {
		printf("malloc failed\n");
		exit(1);
	}

	i = 0;
	srand(20191245);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {

			ele = rand() % 100 + 1;

			ary[i][j] = ele;
		}
	}

	newary = transpose(ary, row, col);

	printf("seed锅龋 20191245肺 积己等 Matrix\n");
	printMatrix(ary, row, col);

	printf("Transpose等 Matrix\n");
	printMatrix(newary, col, row);

	system("pause");
	return 0;
}
int** transpose(int** matrix, int m, int n) {
	int i ,j;
	int** tary;
	tary = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		tary[i] = (int*)malloc(sizeof(int) * m);
	}

	if (tary == NULL) {
		printf("malloc failed\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			tary[i][j] = matrix[j][i];
		}
	}
	return tary;
}

void printMatrix(int** matrix, int m, int n) {
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
}