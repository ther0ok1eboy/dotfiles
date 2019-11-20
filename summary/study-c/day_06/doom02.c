#include <stdio.h>
#include <stdlib.h>

//丢数组给函数的时候,真正的形参是一个可以当作数组
//使用的 变量

//可以跨函数使用存储区
//存储区受生命周期限制
void print(int arr[5]) //这里被调用函数不会为arr[5]提供存储区，因为这些存储区已经存在了
{
	//printf("sizeod(arr) == %d\n", sizeof(arr)); // 4

	//arr[5] 5可以不写
	for(int i = 0; i < 5; i++)
		printf("%d ", arr[i]);

}

int sum_array(int arr[], int len)
{
	//不可以跨文件使用静态全局变量
	static int ret = 0;
	int result = 0;
	for(int i = 0; i < len; i++)
	{
		result += arr[i];
	}

	printf("\n");	
	printf("&ret = %p \n", &result);
	printf("&le  = %p \n", &len);
	printf("&s ret  = %p \n", &ret);
	return result; 
}

void recursion_func(int val)
{
	if(val == 1)
		return;

	val--;
	recursion_func(val);
	printf("%d\t", val);


}

int main()
{
	int arr[5] = {1,2,3,4,5};
	print(arr);
	
	int a = sum_array(arr, 5);
	printf("sum is %d\n", a);

	recursion_func(a);

	if(a == 15)
		exit(-1); //stdlib.h
	printf("sum is %d\n", a);

	return 0;
}
