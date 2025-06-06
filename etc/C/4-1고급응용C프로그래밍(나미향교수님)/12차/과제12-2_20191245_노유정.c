#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	char mail[20];
	int mobile;
} PROFESSOR;
typedef struct {
	char name[20];
	char major[20];
	int id;
	float cgpa;
} STUDENT;
typedef struct {
	char type;
	union {
		PROFESSOR p;
		STUDENT s;
	}u;
}PERSON;
PERSON person;

void printPerson(PERSON person[], int size);
int main(void) {
	PERSON person[4];

	strcpy(person[0].u.p.name, "james");
	strcpy(person[0].u.p.mail, "james@hanmail.net");
	person[0].u.p.mobile = 1097063456;

	strcpy(person[1].u.s.name, "david");
	strcpy(person[1].u.s.major, "computer science");
	person[1].u.s.id = 20010123;
	person[1].u.s.cgpa = 3.10;

	printPerson(*person, 4);
}
void printPerson(PERSON person, int size) {
	int i;
	printf("--------------------------\n");
	for (i = 0; i < size; i++) {
		if (person.type == 'p') {
			printf("name: %s\n", person.u.p.name);
			printf("mail: %s\n", person.u.p.mail);
			printf("mobile: %d\n", person.u.p.mobile);
		}
		else {
			printf("name: %s\n", person.u.s.name);
			printf("major: %s\n", person.u.s.major);
			printf("id: %d\n", person.u.s.id);
			printf("cgpa: %f\n", person.u.s.cgpa);
		}
	}

}