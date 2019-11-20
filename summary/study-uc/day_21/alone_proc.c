#include <stdio.h>
#include <stdlib.h>
#include <open_file.h>

int main(void)
{
	pid_t pid;
	//创建子进程
	pid = fork();
	if(pid == -1)
	{
		perror("error tips:");
		return -1;
	}

	//子进程执行的代码
	if(pid == 0)
	{
		//父进程死之前
		printf("parent of child pid:...%d\n", getppid());
		sleep(2);
		//父进程死之后
		printf("parent of child pid:...%d\n", getppid());
	}
	//父进程执行单代码
	else
	{
		sleep(1); //为了让父进程后死,防止孤儿进程
		exit(0);
	}

	return 0;
}
