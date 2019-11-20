#include <stdio.h>
#include <stdlib.h>
#include <open_file.h>
#include <sys/wait.h>

int main01(void)
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
		printf("parent of child pid:...%d\n", getppid());
		getchar();
		exit(-2);
	}
	//父进程执行单代码
	else
	{
		//异步变同步了(子进程先死,父进程后死)
		wait(NULL);//等待子进程的终止
	}

	return 0;
}

int main02(void)
{
	int status = 0;//退出状态
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
		printf("child pid:...%d\n", getpid());
		getchar();
		exit(-2);
	}
	//父进程执行单代码
	else
	{
		//等待子进程退出,将其退出状态存到status
		wait(&status);
		printf("parent pid...%d\n", getpid());
		//检测子进程是否正常终止
		if(WIFEXITED(status))
			printf("exit number %d\n", WEXITSTATUS(status));
		//检测子进程是否被信号打断
		if(WIFSIGNALED(status))
			printf("signal number %d\n", WTERMSIG(status));

	}

	return 0;
}

//waitpid(2):
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
		printf("child pid:...%d\n", getpid());
		getchar();
		exit(0);
	}
	//父进程执行单代码
	else
	{
	
		//阻塞
		waitpid(-1, NULL, 0);

		//非阻塞,没有子进程终止的时候,返回0
		//int wpid = waitpid(-1, NULL, WNOHANG); //wpid=0;
		printf("parent pid:...%d\n", getpid());
	}

	return 0;
}









