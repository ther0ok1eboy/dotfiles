#include <stdio.h>
#include <stdlib.h>
#include <file_head.h>
#include <dirent.h>
#include <string.h>

char *t(char *d_name, char *temp)
{
	char *file_name = temp;
	if(*d_name == "." |*d_name == "..")
	{
		printf("xxpoo\n");
		return NULL;
	}
	strcat(file_name, "/");
	strcat(file_name, d_name);
	d_name = file_name;

	return d_name;

}

int main(int args, char *argv[])
{
	struct stat buf;
	struct dirent *dir;
	int i = 0;      //循环变量

	//打开文件
	int s = stat(argv[1], &buf);
	if(s == -1)
	{
		perror("error tips:");
		return -1;
	}
	
	//识别文件类型
	switch(buf.st_mode & S_IFMT)
	{
		case S_IFDIR:
		i = 999;
		case S_IFREG:
		i = 1;//GOTO 语句
	}
	
	//打开一个文件夹
	DIR *d = opendir(argv[1]);
	if(NULL == d)
	{
		perror("error tips:");
		return -1;
	}

	//打开成功
	printf("dir open\n");

	while(i)
	{
		dir = readdir(d);
		if(NULL == dir)
			break;
		char *name = 0;
		if(name = t(dir->d_name, argv[1]))
		printf("%s \n", name);
	}

	//关闭文件夹
	closedir(d);
	return 0;
}
