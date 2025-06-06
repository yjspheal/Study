#include <stdio.h>
int main(void) {
	FILE* inFp, * outFp;
	char str;
	int c_u = 0, c_l = 0, c_a = 0, c_b = 0, state;

	inFp = fopen("D:\\input.txt", "r");
	if (inFp == NULL) {
		printf("input file open error !\n");
		return 1;
	}
	outFp = fopen("D:\\output.txt", "w");
	if (outFp == NULL) {
		printf("output file open error !\n");
		return 1;
	}
	while (1) {
		state = fscanf(inFp, "%c", &str);
		if (state == EOF) break;
		if (str == 9 || str == 32) {
			c_b += 1;
		}
		else if (str >= 48 && str <= 57) {
			c_a += 1;
		}
		else if (str >= 65 && str <= 90) {
			c_u += 1;
		}
		else if (str >= 97 && str <= 122) {
			c_l += 1;
		}
	}
	printf("Number of upper case letters : %d\n",c_u);
	printf("Number of lower case letters : %d\n", c_l);
	printf("Number of arabic characters : %d\n", c_a);
	printf("Number of blanks : %d\n", c_b);

	fprintf(outFp, "Number of upper case letters : %d\n", c_u);
	fprintf(outFp, "Number of lower case letters : %d\n", c_l);
	fprintf(outFp, "Number of arabic characters : %d\n", c_a);
	fprintf(outFp, "Number of blanks : %d\n", c_b);

	fclose(inFp);
	fclose(outFp);
	return 0;
}
/* tab 9 space 32 ara 48~57 upper 65~90 lower 97~122 */