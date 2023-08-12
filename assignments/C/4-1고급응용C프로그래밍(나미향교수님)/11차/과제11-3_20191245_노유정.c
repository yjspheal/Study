#include <stdio.h>

void print_str(char**);
void main()
{
	int num, i;
	char* ary, str; 

	printf("Number of strings : ");
	scanf("%d", &num);

	ary = (int*)malloc(sizeof(int) * num);

	for (i = 0; i < num; i++) {
		fputs("Input the string : ", stdout);
		scanf("%s", &str);
		ary[i] = (char*)malloc(sizeof(str));
		ary[i] = str;
	}
	printf("Read complete!!!\n\n");

	print_str(ary);

	free(ary);
	return 0;
}
void print_str(char** ary){
	int j = 0;
	printf("Your strings are :\n");

	while (1) {
		if (ary[j] == NULL) break;

		fputs(ary, stdout);
		j++;
	}
}