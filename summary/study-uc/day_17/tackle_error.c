#include <stdio.h>
#include <errno.h>
#include <string.h>

//系统中有一个全局变量,errno
//记录了最近函数的错误信息(值)
//man 3 函数 看看return有没有errno
//perror() / strerror() man 3 perror自己看

//chmod a-r filename 让文件失去读权限

int main(int args, char* argv[])
{
	extern int errno;
	//打开文件,文件名从命令行的第一个参数传入
	FILE* p_file = fopen(argv[1], "r");
	if(p_file == NULL)
	{
		//printf("open %s fails...%d\n", argv[1], errno);
		//perror("error tips:");
		printf("error tips: %s\n", strerror(errno));
		return -1;
	}	

	printf("open %s sucessful...\n", argv[1]);
	
	fclose(p_file);
	p_file = NULL;
	return 0;
}
