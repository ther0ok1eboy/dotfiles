#include <stdio.h>

int main()
{

/*
//数组名不是存储区，不能被赋值
//数组名代表数组里第一个存储区的地址
	int array[2] = {0};
	printf("array is %p\n", array);        //0x7fff55004f50
	printf("array[0] is %p\n", &array[0]); //0x7fff55004f50
	printf("array[1] is %p\n", &array[1]); //0x7fff55004f54 差4

	printf("sizeof(array) :%ld\n\n",sizeof(array));

*/
//c99 允许数组个数是变量 int num ;array[num]; ==> 变长数组
	int size = 0, core = 0;
	printf("please input the test times\n");
	scanf("%d", &size);
	if(size < 2)
		return 0;
	int arra[size];
	//int arra[size] = {0} //error
	//printf("sizeof(arra) :%ld\n",sizeof(arra));
	
	int min = 1000, max = -1;
	int total_result = 0;
	for(int i = 0; i < size; i++)
	{
		printf("please input the test cores\n");
		scanf("%d", &core);
		arra[i] = core;
		
		total_result += arra[i];
	
		if(min > arra[i])
			min = arra[i];
		if(max < arra[i])
			max = arra[i];
	}

	printf("the max is %d,the min is %d,total is %d\n", max, min, total_result);
	return 0;
}
