#include <file_head.h>
#include <sys/mman.h>
#include <stdio.h>
#include <errno.h>

int main(int args, char* argv[])
{
	int prot = PROT_READ|PROT_WRITE;
	
	//打开文件
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		perror("error tips:");
		return -1;
	}

	//将文件映射到进程的虚拟地址空间
	void *p = mmap(NULL, 6, prot, MAP_SHARED, fd, 0);
	if(MAP_FAILED == p)
	{
		perror("error tips:");
		return -1;	
	}

	//映射成功
	*((int*)p) = 0x12345678;

	//关闭文件描述符
	close(fd);

	//解除映射
	munmap(p, 6);


	return 0;
}	
