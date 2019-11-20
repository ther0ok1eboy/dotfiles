#include <stdio.h>
#include <sys/wait.h>
#include <open_file.h>
int main(void)
{
	char *const envp[] = {"key=value", NULL};
	//创建一个子进程
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("error tips:");
		return -1;
	}

	if(pid == 0)
	{
		//execl("./env", "env", NULL);
		//环境变量不从父进程继承
		execle("./env", "env", NULL, envp);
	}
	else
		wait(NULL);
	return 0;
}
