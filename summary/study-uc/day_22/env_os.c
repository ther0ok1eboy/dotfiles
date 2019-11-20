#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(void)
{
	//获取环境变量的值
	//普通变量是当前进程私有的,不会通过bash继承给子进程
	//环境变量PATH才会被继承到子进程
	char *str = getenv("path");
	if(!str)
	{
		printf("not found env...");
		return -1;
	}
	printf("%s\n", str);

	//向进程增加环境变量
	setenv("name", "sorria", 0);//相同 0不改非0改
	str = getenv("name");
	if(!str)
	{
		printf("not found env...");
		return -1;
	}
	printf("%s\n", str);
	setenv("name", "jason", 1);
	str = getenv("name");
	if(!str)
	{
		printf("not found env...");
		return -1;
	}
	printf("%s\n", str);
#if 0
	//删除指定环境变量
	unsetenv("name");
	str = getenv("name");
	if(!str)
	{
		printf("not found env...");
		return -1;
	}
	printf("%s\n", str);
#endif
	
#if 0
	//清除环境变量,设置全局环境变量environ为NULL
	int cl = clearenv();
	if(cl)
	{
		printf("clear error\n");
		return -1;
	}
	if(NULL == environ)
	{
		printf("clear sucess\n");
	}
#endif
	
	char buf[128];
	strcpy(buf, "name=/jason/sorria");
	putenv(buf);
	str = getenv("name");
	if(!str)
	{
		printf("putenv() not found env...");
		return -1;
	}
	printf("%s\n", str);


	return 0;
}
