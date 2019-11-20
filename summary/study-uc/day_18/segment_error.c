#include <stdio.h>
#include <string.h>

void test()
{
	char buff[32]; //buff的地址已经确定,为常亮
	//buff = "abc";  //不能把abc的地址给buff
	//printf("%s\n", buff++) error 改变了buff的地址
	strcpy(buff, "abc"); //一个字符一个字符赋值的
	printf("%s\n", buff);
}

int main(void)
{
	int i = 100;
	//int *p_i = (int *)30000000;
	//*p_i = 128; // 这时有虚拟地址却没有物理地址与之对应
	 	    //也有可能这个地址的数据是ro
	//printf("p_i = %d\n", *p_i);


	test();
	return 0;
}
