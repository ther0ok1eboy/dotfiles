#include <stdio.h>
#include "int_get.h"

int int_get(void)
{
	printf("please input a intiger\n");
	int num = 0;
	scanf("%d", &num);
	return num;

}
