#include <stdio.h>

int main()
{
	
	printf("please input two number which is an erea\n");
	int num1 ,num2 ,sum = 0 ,result = 0;
	scanf("%d %d",&num1 ,&num2);

	//swap two number if num1 > num2
	if(num1 > num2)
	{
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	//质数：
	/*
	//1 7 ==> 1 3 5 7
	for(int i = num1 ;i <= num2 ;i++)
	{
		if(i & 1)
			result += i;

	}

	printf("result is %d\n",result);
	*/

	//素数：
	int flag = 0;
	for(int i = num1 ;i <= num2 ;i++)
	{
		flag = 1; // is
		for(int j = 2; j < i - 1; j++)
		{
			if(!(i % j))
			{
				flag = 0;// is not
				break;
			}
		}

		if(flag == 1)
		printf("%d ",i);
	}

	
	return 0;
}
