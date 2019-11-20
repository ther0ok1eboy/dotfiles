#include <stdio.h>


int sum(int val)
{
	if(val == 1)
		return 1;

	return sum(val - 1) + val;
}

//斐波那切数
int fab1(int val)
{
	//会作很多重复的运算
	if(val == 1 || val == 0)
		return 1;
	return fab1(val - 2) + fab1(val - 1);
}

int fab2(int val)
{
	//记录以前算过的结果
	static int arr[50]; //一定要声明为静态的
	if(val == 1 || val == 0)
		return 1;
	if(arr[val - 2] == 0) //if(!arr[val - 2])
	{
		arr[val - 2] = fab2(val - 2);
	}

	if(arr[val - 1] == 0)
	{
		arr[val - 1] = fab2(val - 1);
	}

	return arr[val - 2] + arr[val - 1];

}

int main()
{

	int ret = sum(100);

	ret = fab2(45);
	printf("ret = %d\n", ret);
	
	return 0;
}
