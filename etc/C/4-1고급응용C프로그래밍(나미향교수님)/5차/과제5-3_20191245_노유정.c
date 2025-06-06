#include <stdio.h>
#include <math.h>

int main(void) {
	float bound = 1.0e-5;
	float a, b, c, D, D1,root1, root2;

	printf("Enter a, b, c: ");
	scanf("%f %f %f", &a, &b, &c);

	if ((a == 0) && (b == 0))
		printf("No root exists.\n");

	else if ((a == 0) && (b != 0))
		printf("root %f\n", -c / b);

	else {
		D = b * b - 4 * a * c;
		if (fabs(D) <= bound)
			printf("root %f\n", -b / (2 * a));

		else if (D > 0) {
			D = sqrt(D);
			root1 = (-b + D) / (2 * a);
			root2 = (-b - D) / (2 * a);
			printf("root1 = %.4f and root2 = %.4f.\n", root1, root2);
		}

		else
			printf("No root exists.\n");
	}
}