#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}Coor;

Coor* gain_coor(void)
{
	Coor* coor = (Coor* )malloc(sizeof(Coor) * 2);
	if(!coor){return NULL;}

	coor->x = 1;
	coor->y = 1;
	(coor + 1)->x = 5;
	(coor + 1)->y = 5;

	return coor;

}

void main(int args, char* argv[])
{
	Coor* coor = gain_coor();
	if(coor)
	{	
		printf("up left coor: (%d,%d)\n", coor->x, coor->y);
		printf("down right coor: (%d,%d)\n", (coor + 1)->x, (coor + 1)->y);	
	}
	free(coor);
	coor = NULL;


	//可以把动态分配的存储区内容都设置为0
	int num = 5, size = sizeof(int);
	int* calloc_num = (int* )calloc(num, size);//返回值和malloc一样
	if(!calloc_num){return;}

	//可以调整一段动态分配内存里的存储区个数
	//动态分配的内存必须连续
	//尽量少使用realloc()
	calloc_num = realloc(calloc_num, 10);    //(调整个数的实现方式和vector一样)




}
