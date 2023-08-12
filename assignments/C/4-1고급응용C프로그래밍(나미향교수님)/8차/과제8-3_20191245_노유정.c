#include <stdio.h>

void add_element(int value, int set[], int* cp);
void delete_element(int value, int set[], int* cp);
int has_element(int value, int set[], const int* cp);
void print_set(int set[], const int* cp);
int main(void) {
	int ary[30] = { 0 };
	int el = 0, num;
	char fun;
	int* el_cnt = &el;

	printf("Commands : a 5 ==> adds 5 to the set.\n");
	printf("           d 5 ==>  deletes 5 from set.\n");
	printf("           q ==> quit.\n");
	printf("=======================================\n");
	
	while (1) {
		printf("Enter commands : ");
		scanf("%c", &fun);
		if (fun == 'q') {
			break;
		}

		scanf(" %d", &num);
		while (getchar() != '\n');

		if (fun == 'a') {
			add_element(num, ary, el_cnt);
			print_set(ary, el_cnt);
		}
		else if (fun == 'd') {
			delete_element(num, ary, el_cnt);
			print_set(ary, el_cnt);
		}
		else {
			printf("wrong command. try again.\n");
		}
	}
}

void add_element(int value, int set[], int* cp) {
	if (has_element(value, set, cp) == -1) {
		set[*cp] = value;
		*cp = *cp + 1;
	}
	else { //원소가 원래 있어서 넘김
		printf("%d is already in the set.\n", value);
	}
}
void delete_element(int value, int set[], int* cp) {
	int i, bin;
	bin = has_element(value, set, cp);
	if (bin == -1) { //원소가 원래 없어서 못지움
		printf("%d is not in the set.\n", value);
	}
	else {
		for (i = bin; i < *cp; i++) {
			set[i] = set[i + 1];
		}
		*cp = *cp - 1;
	}
}
int has_element(int value, int set[], const int* cp) {
	int i;
	for (i = 0; i <= *cp; i++) {
		if (set[i] == value) {
			return i;
		}
	}
	return -1;
}
void print_set(int set[], const int* cp) {
	int i;
	for (i = 0; i < *cp; i++) {
		printf("%d ", set[i]);
	}
	printf("\n");
}