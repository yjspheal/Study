#include <stdio.h>

int main(void) {
	char veh_type;
	int hour; int min; int min_sum;

	printf("차량 종류 : ");
	scanf("%c", &veh_type);
	printf("시간 : ");
	scanf("%d", &hour);
	printf("분 : ");
	scanf("%d", &min);
	min_sum = (hour * 60 + min) / 10;

	if ((veh_type == 'C') || (veh_type == 'c')) {
		printf("주차요금 : %d원\n", min_sum * 2000);
	}

	if ((veh_type == 'B') || (veh_type == 'b')) {
		printf("주차요금 : %d원\n", min_sum * 3000);
	}

	if ((veh_type == 'T') || (veh_type == 't')) {
		printf("주차요금 : %d원\n", min_sum * 5000);
	}
}

