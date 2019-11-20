#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* malloc_value()
{

	int* malloc_value = (int* )malloc(sizeof(int));
	if(NULL == malloc_value){return NULL;}

	*malloc_value = 6666;
	return malloc_value;
}

int* create(int size)
{
	//被调函数动态分配内存,调用函数使用
	//造成使用和释放函数分离
	int* malloc_num = (int* )malloc(size*sizeof(int));
	if(NULL == malloc_num){return NULL;}

	for(int i = 0; i < size; i++)
		*(malloc_num + i) = rand() % 36 + 1;
	for(int i = 0; i < size; i++)
		printf("%d ", *(malloc_num + i));
	return malloc_num;
}


int* gain_coor()
{

	int* malloc_num = (int* )malloc(4*sizeof(int));
	if(NULL == malloc_num){return NULL;}
	*(malloc_num + 0) = 1;
	*(malloc_num + 1) = 1;
	*(malloc_num + 2) = 5;
	*(malloc_num + 3) = 5;
	return malloc_num;
}

void main(int args, int** argv)
{
	//malloc可以动态分配一组连续的字节
	int* malloc_num = (int* )malloc(3*sizeof(int));
	//其返回值(void*)是分配好的第一个字节的地址,而且不一定会分配成功
	if(NULL == malloc_num){return;}
	//要强转才能使用
	
	for(int i = 0; i < 3; i++)
		 *(malloc_num + i) = i;	
	for(int i = 0; i < 3; i++)
		printf("%d \n", *(malloc_num + i));
	

	printf("malloc_value = %d\n", *malloc_value());
	free(malloc_value());

	srand(time(NULL));
	int* p_create = create(5);
	if(p_create)
	{
		create(5);
		free(malloc_num);
	}
	

	free(malloc_num);
	malloc_num = NULL;


	int* gain = gain_coor();
	if(gain)
	{
		printf("\n");
		printf("up left coor: (%d,%d)\n", *(gain), *(gain + 1));
		printf("down right coor: (%d,%d)\n", *(gain + 2), *(gain + 3));
	
	}



}
