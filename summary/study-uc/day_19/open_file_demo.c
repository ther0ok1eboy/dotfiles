#include <stdio.h>
#include <file_head.h>

int read_only(int args, char* argv[])
{

	int fd = 0;
	//打开文件,以只读方式打开
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("error tips :");
		return -1;
	}

	printf("open sucessful\n");
	//关闭文件
	close(fd);
	return 0;
}

int write_only(int args, char* argv[])
{
	int fd = 0;
	int flags = O_WRONLY|O_CREAT|O_EXCL;
	//打开文件,以只写方式打开,文件存在则报错,不存在
	//则创建并设置权限
	fd = open(argv[1], flags, 0666);
	if(fd == -1)
	{
		perror("error tips :");
		return -1;
	}

	printf("open sucessful\n");
	//关闭文件
	close(fd);
	
	return 0;
}

int write_trunc(int args, char* argv[])
{

	int fd = 0;
	int flags = O_WRONLY|O_CREAT|O_TRUNC;
	//打开文件,以只写方式打开,文件存在则清空,不存在
	//则创建并设置权限
	fd = open(argv[1], flags);
	if(fd == -1)
	{
		perror("error tips :");
		return -1;
	}
	printf("open sucessful\n");
	//关闭文件
	close(fd);
	
	return 0;
}

int read_func(int args, char* argv[])
{

	void *buff = NULL;
	int fd = 0;
	int flags = O_WRONLY|O_CREAT|O_TRUNC;
	//打开文件,以只写方式打开,文件存在则清空,不存在
	//则创建并设置权限
	fd = open(argv[1], flags);
	if(fd == -1)
	{
		perror("error tips :");
		return -1;
	}
	printf("open sucessful\n");
	//关闭文件
	close(fd);
	
	return 0;
}

int cat_demo(int args, char* argv[])
{
	int fd = 0;  //文件描述符
	int ret = 0; //实际读取到的数据个数
	char buf[128] = {0};
	int flags = O_RDONLY;

	//打开文件,以只读方式打开
	fd = open(argv[1], flags);
	if(fd == -1)
	{
		perror("error tips :");
		return -1;
	}

	while((ret = read(fd, buf, 128)) > 0)
	
		//从文本中读数据到buf中
		//ret = read(fd, buf, 128);
		
		//到达文件末尾
		//if(ret == 0)
		//	break;

		//将buf中的数据输出到显示屏
		//1 为标准输出的文件描述符
		write(1, buf, ret);


	//关闭文件
	close(fd);
	return 0;

}

int main(int args, char* argv[])
{
	
	//read_only(args, argv);
	//write_only(args, argv);
	//write_trunc(args, argv);
	cat_demo(args, argv);
	return 0;
}
