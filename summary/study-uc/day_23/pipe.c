#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <open_file.h>
#include <sys/wait.h>

int main(void)
{
	char *msg = "ICP sucess...\n";
	char buf[128];

	int fd[2];
	//创建管道
	int pp =pipe(fd);
	if(pp == -1)
	{
		perror("pipe:");
		return -1;
	}

	//创建子进程
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork:");
		return -1;
	}

	if(pid == 0)
	{
		//子进程该做的事
		close(fd[0]); //关闭读端
		write(fd[1], msg, strlen(msg)); //向管道写段写入数据
		exit(0); //退出

	}
	else
	{
		//父进程该做的事
		close(fd[1]); //关闭写端
		int realise_read = read(fd[0], buf, 128); //从管道读端读数据到buf
		write(1, buf, realise_read); //将buf显示到屏幕上
		wait(NULL); //等待子进程退出 回收子进程资源
	}
	return 0;
}
