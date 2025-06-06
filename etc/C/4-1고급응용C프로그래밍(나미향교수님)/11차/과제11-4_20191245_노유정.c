#include <stdio.h>
#include <string.h>

int insertString(char* str1, char* str2, int idx);
int main(void) {
	char str[100] = "\0";
	char istr[100];
	int idx, res;

	*str = "Necessity is the Mother of Invention.";

	printf("This program inserts a string to a specific position you want.\n\n");

	printf("Original string : Necessity is the Mother of Invention.\n");
	printf("Enter a string to insert : ");
	scanf("%s", &istr);

	printf("Where to do you want to insert? : ");
	scanf("%d", &idx);

	res = insertString(str, istr, idx);
	printf("\nResult : ");
	if (res == 0) {
		printf("%s\n", &str);
	}
	else {
		printf("%s\n", &str);
	}

	return 0;
}
insertString(char* str1, char* str2, int idx) {
	char res[100];
	if (strlen(str1) < idx) return 0;

	else {
		strncpy(res, str1, idx);
		strcat(res, str2);
		strcat(res, str1 + idx);
		*str1 = res;
	}
}