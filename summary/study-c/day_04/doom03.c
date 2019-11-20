#include <stdio.h>
#include <unistd.h> // sleep() / win ==> Windows.h Sleep()

int main(void)
{
	//for(1; 2; 3)
	//{ 4; }
	// 12 432 432 432 432 ...
	//for(;;)   infinite loop
	//	printf("xxoo");
	// break     跳过一个循环，不执行这个循环
	// continue  跳到循环末尾,继续下一次循环
	
	/*
	int num = 0;
	for(;;)
	{
	
		printf("please input a number and input <0 to pause\n");
		scanf("%d",&num);
		if(num < 0)
			break;
		if(num >= 0)
			printf("%d\n",num);
	
	}

	int time = 0;
	while(1)
	{
		printf("%d\r",time);
		fflush(stdout);
		time++;
		sleep(1);
		if(time == 10)
			break;
	
	}

//////////////////////////////////////////////////////////////////////////////

	int num = 0;
	int numarray[5] = {0};
	for(int i = 0; i < 5; i++)
	{
		printf("please data among 5\n");
		scanf("%d",&num);
		numarray[i] = num;
	
	}

	for(int i = 4; i >= 0; i--)
		printf("%d\t",numarray[i]);
	
*/

	int num = 1, i = 0, flag = 0, numcount = 0;
	int numarray[10] = {0};
	printf("please input a number which is not over 8 bits\n");
	scanf("%d",&num);

	//obtain each bit to add to numarray
	while(num)
	{
		numarray[i] = num % 10;
		num = num / 10;
		numcount++;
		i++;
	}
	
	if(numcount == 8)
		printf("input error!!\n");
	
	//count the times of each bit
	for(int i = 0; i < numcount; i++)
	{
		//判断i前面是否出现过相同的数
		flag = 0;
		for(int j = 0; j < i; j++)
		{
			if(numarray[i] == numarray[j])
			{
				flag = 1;
				break;
			}

		}

		int count = 0;
		for(int j = 0; j < numcount && !flag; j++)
		{
			if(numarray[i] == numarray[j])
			{
				count++;
			}
		
		}

		//避免重复打印结果
		if(flag == 0)
		printf("number%d's count is %d\n",numarray[i],count);

	}


	return 0;
}
