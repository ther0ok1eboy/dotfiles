#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int stall = 0;
int all = 0;

void add()
{
	int *p = (int*)malloc(4);
	printf("%d\n", getpid());
	static int stac = 0;
	int may = 0;
	printf("局部变量: %p\n", &may);
	printf("静态局部变量: %p\n", &stac);
	getchar();
}

int main(void)
{
	add();
	printf("静态全局变量: %p\n", &stall);
	printf("全局变量: %p\n", &all);
}



