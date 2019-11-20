#include <open_file.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//创建子进程
	pid_t pid = fork();
	if(pid  == -1)
	{
		perror("error tips:");
		return -1;
	}

	if(pid == 0)
	{
		//子进程执行的代码
		printf("child process pid:%d", getpid());//ps -aux看看Z+
		exit(0);
	}
	//让子进程先退出,父进程卡住,让父进程无法为子进程回收资源
	else
		getchar();
	return 0;
}
