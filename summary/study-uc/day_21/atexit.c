#include <open_file.h>
#include <stdlib.h>
#include <stdio.h>

void first_reg(void)
{
	printf("child, do you father things...%d\n", getpid());
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
	atexit(first_reg);
	atexit(second_reg); //调用时与注册顺序相反

	//创建子进程
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("error tips:");
		return -1;
	}
	
	if(pid == 0)
		exit(0);
	else
		printf("your father never die...\n");
	getchar();
	return 0;
}
