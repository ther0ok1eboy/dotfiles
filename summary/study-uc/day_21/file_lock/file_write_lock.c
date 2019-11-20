#include <stdio.h>
#include <file_head.h>

int main(int args, char *argv[])
{
	struct flock w_lock;

	printf("get pid:%d\n", getpid());
	//只写打开
	int fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		perror("error tips:");
		return -1;
	}

	//初始化锁的内容
	w_lock.l_type = F_WRLCK; //指定锁的类型
	//指定锁的区域
	w_lock.l_whence = SEEK_SET;
	w_lock.l_len = 128;
	w_lock.l_start = 0;

	//对文件加写锁
	int f_lock = fcntl(fd, F_SETLKW, &w_lock); //阻塞
	//int f_lock = fcntl(fd, F_SETLK, &w_lock);    //非阻塞
	if(f_lock == -1)
	{
		perror("error tips:");
		return -1;
	}

	printf("fcntl() sucessful...\n");
	getchar(); //方便在两个进程中测试

	//关闭文件描述符,有可能造成锁的丢失
	close(fd);
	return 0;
}
