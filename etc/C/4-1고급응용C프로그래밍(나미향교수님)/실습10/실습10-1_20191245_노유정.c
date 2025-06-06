#include <stdio.h>

int main(void) {
	FILE *inFp, * outFp;
	char name[20];
	int age, count = 0; double height, avg_h = 0, avg_a = 0; int state;

	inFp = fopen("D:\\studentIn.txt", "r");
	if (inFp == NULL) {
		printf("input file open error !\n");
		return 1;
	}
	outFp = fopen("D:\\studentOut.txt", "w");
	if (outFp == NULL) {
		printf("output file open error !\n");
		return 1;
	}
	while (1) {
		state = fscanf(inFp, "%s %d %lf", &name, &age, &height);
		if (state == EOF) break;
		avg_h += height; avg_a += age; count += 1;
		fprintf(outFp, "%.1lf %d %s\n", height, age, name);
	}
	avg_h /= count; avg_a /= count;
	fprintf(outFp, "Average height: %.1lf  Average age: %d", avg_h, (int)avg_a);
	fclose(inFp);
	fclose(outFp);
	return 0;
}