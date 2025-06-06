#include <stdio.h>
int main(void) {
	FILE* inFp, * outFp;
	char str[100];
	int c_u = 0, c_l = 0, c_a = 0, c_b = 0, state;
	int* pcu = c_u, * pcl = c_l, * pca = c_a, * pcb = c_b;

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
	while (fgets(str, sizeof(str), inFp)) {
		state = fgets(str, sizeof(str), inFp);

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
	fputs("Number of upper case letters : \n", outFp);
	fputs(pcu, outFp);
	fputs("\nNumber of lower case letters : \n", outFp);
	fputs(pcl, outFp);
	fputs("\nNumber of arabic characters : \n", outFp);
	fputs(pca, outFp);
	fputs("\nNumber of blanks : \n", outFp);
	fputs(pcb, outFp);
	fputs("\n",outFp);

	fputs("Number of upper case letters : \n", stdout);
	fputs(pcu, stdout);
	fputs("\nNumber of lower case letters : \n", stdout);
	fputs(pcl, stdout);
	fputs("\nNumber of arabic characters : \n", stdout);
	fputs(pca, stdout);
	fputs("\nNumber of blanks : \n", stdout);
	fputs(pcb, stdout);
	fputs("\n", stdout);

	fclose(inFp);
	fclose(outFp);
	return 0;
}