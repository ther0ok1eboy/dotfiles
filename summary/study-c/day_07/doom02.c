#include <stdio.h>

int* read01(void)
{

	//int num = 0; error 返回了局部变量的地址
	static int num = 0;
	printf("please input a number to read\n");
	scanf("%d", &num);
	return &num;

}

int* read02(int* p_num)
{
	
	printf("please input a number to read\n");
	scanf("%d", p_num);
	return p_num;

}

int main()
{
	int num = 0;
	int* p_num = read01();
	printf("p_num = %d\n", *p_num);
	
	p_num = read02(&num);
	printf("p_num = %d\n", *p_num);
	
	return 0;

}
