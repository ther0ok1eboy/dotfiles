#include "bash_.h"
#include <stdio.h>

int main(int args, char *argv[])
{
	while(1)
	{

		char *arg[32];
		char buf[64];
		char str[64];

		printf("%s:~$ ", getcwd(str, 64));
		fgets(buf, 64, stdin);
		buf[strlen(buf) - 1] = '\0';//去掉fget()导致的末尾\n
		int len = strlen(buf);
	
		//将命令存放在arg[0]和arg[1]中
		turn(arg, buf, len);
	
		//创建bash的子进程
		pid_t pid = fork();
		if(pid == 0)
		{
			if(!strcmp(arg[0], "cat"))
				cat(arg[0], arg[1]);
		
			if(!strcmp(arg[0], "ls"))
				ls(arg[0], arg[1]);

			if(!strcmp(arg[0], "ps"))
				ps(arg[0], arg[1]);
		
			if(!strcmp(arg[0], "which"))
				which(arg[0], arg[1]);	
			
			if(!strcmp(arg[0], "env"))
				env(arg[0], arg[1]);
		
			printf("not found the %s command...\n", arg[0]);
			exit(-1);
		}
		else
		{
			wait(NULL);
		}

	}
	
	return 0;
}
