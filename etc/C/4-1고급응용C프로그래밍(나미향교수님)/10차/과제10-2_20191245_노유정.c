#include <stdio.h>

int main(void) {
	FILE* inFp, * outFp;
	int num, count = 0, state;

	inFp = fopen("D:\\FILE1.txt", "r");
	if (inFp == NULL) {
		printf("input file open error !\n");
		return 1;
	}
	outFp = fopen("D:\\FILE2.txt", "w");
	if (outFp == NULL) {
		printf("output file open error !\n");
		return 1;
	}
	while (1) {
		state = fscanf(inFp, "%d", &num);
		if (state == EOF) break;
		if (num >= 90){
			fprintf(outFp, "%d\n", num);
			count += 1;
		}
	}
	printf("Start of Program\n\n\n");
	printf("There were %d scores over 90.\n\n", count);
	printf("End of Program\n");

	fclose(inFp);
	fclose(outFp);
	return 0;
}