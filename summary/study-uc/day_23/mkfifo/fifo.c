#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int args, char *argv[])
{

	//创建管道文件,文件名通过argv[1]传递进来
	int mf = mkfifo(argv[1], 0644);
	if(mf == -1)
	{
		perror("pipe:");
		return -1;
	}
	
	printf("pipe file %s sucess...\n", argv[1]);

	return 0;
}
