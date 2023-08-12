#include <stdio.h>
#include <stdlib.h>

void delete_char(char* ar, int lth, char ss);
int main(void) {
	char Arr[] = { 'G','O','O','D','M','O','R','N','I','N','G','\0'};
	char s;
	char* ar;
	int i = 0;

	printf("삭제 전 : ");
	
	while (Arr[i] != '\0') {
		printf("%c", Arr[i]);
		i++;
	}
	printf("\n삭제할 문자 : ");
	scanf("%c", &s);

	delete_char(Arr, i, s);

	printf("삭제 후 : ");
	i = 0;
	while (Arr[i] != '\0') {
		printf("%c", Arr[i]);
		i++;
	}
	printf("\n");

	system("pause");
	return 0;
}
void delete_char(char *ar, int lth, char ss) {
	int i = 0 , j;
	for (i = 0; i < lth; i++) {
		if (ar[i] == ss) {
			for (j = i; j < lth; j++) {
				ar[j] = ar[j + 1];
			}
			i--;
		}
	}
}