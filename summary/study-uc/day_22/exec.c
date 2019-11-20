#include <unistd.h>
#include <open_file.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	/*
	char *const _argv[] = {"ps", "-o"\
	, "pid,ppid,pgrp,session,comm", NULL}; 
	//创建子进程
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("error tips:");
		return -1;
	}

	if(pid == 0)
	{
		//使用ps命令的映像替换从父进程继承来的进程映像
		//execvp("ps", _argv);
		//execv("/bin/ps", _argv);
		//execl("/bin/ps", _argv[0], _argv[1], _argv[2], NULL);
		execlp("ps", _argv[0], _argv[1], _argv[2], NULL);
		//以下代码在程序出错的时候才能执行,因为已经被ps替换掉了
		perror("error tips:");
		exit(0);
	}
	else
	{
		//阻塞等待子进程结束
		wait(NULL);
	}
	*/

	//不创建子进程,直接使用ps命令的映像替换当前进程映像
	execl("/bin/ps", "ps", "-o", "pid,ppid,pgrp,comm", NULL);
	return 0;
}
