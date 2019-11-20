
#include <stdlib.h>
#include <open_file.h>
#include <stdio.h>

//遗言函数
void reg(int n, void *arg)
{
	printf("n(return n) = %d arg = %s\n", n, (char *)arg);
	return;
}

void second_reg(void)
{
	printf("child, do you things...%d\n",getpid());
	return;
}

int main(void)
{
	//向进程注册遗言函数
	on_exit(reg, "void *arg");//第二个参数void*会传到reg函数的void*
	
	//创建子进程
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("error tips:");
		return -1;
	}
	
	if(pid == 0)
		printf("your son never die...\n");
	else
		printf("your father never die...\n");
	//getchar();
	return 666;
}
