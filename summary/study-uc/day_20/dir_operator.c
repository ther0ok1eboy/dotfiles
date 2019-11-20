#include <stdio.h>
#include <file_head.h>
#include <dirent.h>

//rewinddir(3) scandir(3) seekdir(3) telldir(3)
//自己下去看自己下去试

int main(int args, char *argv[])
{
	struct dirent *dir;

	//打开一个文件夹
	DIR *d = opendir(argv[1]);
	if(NULL == d)
	{
		perror("error tips:");
			return 0;
	}

	printf("open sucessfull\n");

	//遍历文件夹里的所以文件
	while(1)
	{
		dir = readdir(d);
		if(NULL == dir)
			break;
		printf("%s ", dir->d_name);
		//printf("%lu ", dir->d_ino);
	}	
	printf("\n");

	//关闭文件
	closedir(d);
	return 0;
}
