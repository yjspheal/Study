#include <stdio.h>
#include <stdlib.h>
#include <time.h>


///int main(void) {
	///int range;
	///range = 6;
	///srand(time(NULL));
	///printf("The random number is %d\n", rand() % range + 1);
	///return 0;
///}

int main(void) {
	int range;
	range = 6 * 3;
	srand(time(NULL));
	printf("The random number is %d\n", (rand()*3 + 1) % range);
	return 0;
}

