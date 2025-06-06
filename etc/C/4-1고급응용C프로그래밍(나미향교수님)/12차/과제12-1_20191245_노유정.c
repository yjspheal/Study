#include <stdio.h>

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

void printPerson(PERSON ps);
int main(void) {
	PERSON person1, person2;
	strcpy(person1.u.p.name , "james");
	strcpy(person1.u.p.mail, "james@hanmail.net");
	person1.u.p.mobile = 1097063456;

	strcpy(person2.u.s.name, "david");
	strcpy(person2.u.s.major, "computer science");
	person2.u.s.id = 20010123;
	person2.u.s.cgpa = 3.10;

	printPerson(person1);
	printPerson(person2);
}
void printPerson(PERSON ps) {

	printf("--------------------------\n");
	if (ps.type == 'p') {
		printf("name: %s\n", ps.u.p.name);
		printf("mail: %s\n", ps.u.p.mail);
		printf("mobile: %d\n", ps.u.p.mobile);
	}
	else {
		printf("name: %s\n", ps.u.s.name);
		printf("major: %s\n", ps.u.s.major);
		printf("id: %d\n", ps.u.s.id);
		printf("cgpa: %f\n", ps.u.s.cgpa);
	}

}