#include <file_head.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int args, char *argv[])
{
	//只写 文件不存在则创建文件并设置权限 存在则清零
	int flags = O_WRONLY|O_CREAT|O_TRUNC;
	char *msg = "this is a test...";

 	//打开文件
	int fd = open(argv[1], flags, 0644);
  	if(fd == -1)
	{
		perror("error tips: ");
		return -1;
	}	
	//打开成功
	
	//0 1 2
	//输出到显示屏
	write(1, msg, strlen(msg));

	//将文件描述符1重定义到argv[1]丢进来的文件
	dup2(fd, 1);

	//关闭文件
	close(fd);

	write(1, msg, strlen(msg));
        return 0;
}
