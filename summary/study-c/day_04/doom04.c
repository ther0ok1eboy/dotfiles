#include <stdio.h>

int main()
{

	//doom03.c改进后:
	int num = 0;
	int numarray[10] = {0};
	printf("please input a number which is under 8 bits\n");
	scanf("%d",&num);

	do //为了应对num为0的情况,至少要循环一次
	{
		numarray[num % 10]++;
		num = num / 10;
	
	}
	while(num);

	for(int i = 0; i < 10; i++)
	{
		if(numarray[i])
			printf("number %d's count is %d\n", i, numarray[i]);
	
	
	}

	return 0;
}
