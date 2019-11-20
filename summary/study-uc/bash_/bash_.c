#include "bash_.h"

//将命令分成两段放两个数组
void turn(char *arg[] ,char *buf, int len)
 {
          char *temp = buf;
	  char *b;
          int i = 0;
          while(1)
          {
		  if(*temp == ' ' || *temp == '\0')
			  break;
                  i++;
                  *b++=*temp++;
          }
          *b='\0';
	  arg[0] = b - i;
	  if(i != len)
	  	arg[1] = buf + i + 1;
	  else
		arg[1] = NULL;
	  
	  return;
 }

//cat 命令:
void cat(char *a, char *b)
{
	if(NULL == b)
	{
		printf("cat: no assignment for cat...\n");
		exit(0);
	}
	
	execl("/bin/cat", a,b, NULL);
	exit(0);
}

//ls 命令
void ls(char *a, char *b)
{
	if(NULL != b)
		execl("/bin/ls", a, b, NULL);
	else
		execl("/bin/ls", a, NULL);

	exit(0);
}

//ps 命令
void ps(char *a, char *b)
{
	if(NULL != b)
		execl("/bin/ps", a, b, NULL);
	else
		execl("/bin/ps", a, NULL);

	exit(0);
}

//which 命令
void which(char *a, char *b)
{
	if(NULL != b)
		execl("/usr/bin/which", a, b, NULL);
	else
		execl("/usr/bin/which", a, NULL);

	exit(0);
}

//env 命令
void env(char *a, char *b)
{
	if(NULL != b)
		execl("/usr/bin/env", a, b, NULL);
	else
		execl("/usr/bin/env", a, NULL);

	exit(0);
}

