#include <stdio.h>

//fprintf() 和 fscanf()是对  文本文件  进行操作的函数
//这两个函数效率较低 不适合处理大量数据文件

int main(int args, char* argv[])
{
	int write_arr[] = {1, 22, 333, 4444, 55555};


	//可以按照规定格式把数字记录到txt文件里
	//fprintf(FILE* p_file, "%d", int_num);
	FILE* p_file = fopen("a.txt", "w");
	if(!p_file){return 0;};
	
	//存储器 ==> txt
	for(int i = 0; i < sizeof(write_arr) / sizeof(int); i++)
	{
		fprintf(p_file, "%d ", write_arr[i]);
	}
	fclose(p_file);
	p_file = NULL;

	
	
	//可以从txt里获取数字记录到存储器里
	//fscanf(FILE* p_file, "%d", &int_num)
	int get_arr[5] = {0};
	p_file = fopen("a.txt", "r");
	if(!p_file){return 0;};
	
	//txt ==> 存储区
	for(int i = 0; i < 5; i++)
	{
		fscanf(p_file, "%d ", &get_arr[i]);
	}

	for(int i = 0; i < 5; i++)
	{
		printf("get_arr = %d\n", get_arr[i]);
	}
	fclose(p_file);
	p_file = NULL;


	

	return 0;
}
