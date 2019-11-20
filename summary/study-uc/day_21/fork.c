#include <stdio.h>
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
		printf("child process...%d\n", getpid());
		printf("parent of child pid:...%d\n", getppid());
	}
	//父进程执行单代码
	else
	{
		printf("parent process...%d\n", getpid());
		sleep(1); //为了让父进程后死,防止孤儿进程
	}

	printf("hello process...\n");

	getchar();
	return 0;
}
