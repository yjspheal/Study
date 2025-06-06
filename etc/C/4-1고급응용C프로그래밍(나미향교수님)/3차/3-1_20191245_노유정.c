#include <stdio.h>

int main(void)
{
	float r;
	printf("원의 반지름을 입력하세요.\n");
	printf("반지름 : ");
	scanf("%f", &r);
	r = 3.14 * r * r;
	printf("원의 넓이는 %.2f입니다.\n", r);
	return 0;
}	
