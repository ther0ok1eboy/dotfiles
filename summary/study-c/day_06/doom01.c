#include <stdio.h>

//一个函数多次调用时，其变量的存储区域 可能 是不同的
//被调用函数为每一个丢过来的数据提供一个存储区
//
int func(int x)
{
	//volatile 可以被其他函数改写
	volatile int y = 0;
	if(x < 1)
		return y = x;
	if(x >= 1 && x < 10)
		return 2 * x - 1;
	if(x >= 10)
		return 3 * x -11;
}

int func1(int val1, int val2)
{
	int temp = val1 > val2 ? val1 : val2;
	while(1)
	{
		if(temp % val1 == 0 && temp % val2 == 0)
			break;
		temp++;
	}
	
	return temp;
}

int main()
{
	/*
	int size = 3, num = 0;
	printf("please input some of times\n");
	scanf("%d", &size);
	int testarray[size];

	printf("please input some numbers\n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		testarray[i] = num;
	
	}

	for(int i = size - 1; i >= 0; i--)
		printf("%d ", testarray[i]);
	*/

//////////////////////////////////////////////////////////////////////////////

	printf("please input the value of x\n");
	int x = 0;
	scanf("%d", &x);
	int y = func(x);
	printf("y = %d\n", y);
	
	int val1 = 10, val2 = 35;
	y = func1(val1, val2);
	printf(" %d\n", y);
	
	return 0;
}
