#include <stdio.h>
#include <string.h>

int _strtok(void)
{
	char buf[] = "cat /usr/bin/cat@xxoo";
	char *ret = strtok(buf, " ");
	if(ret)
		printf("ret = %s\n", ret);
	
	ret = strtok(NULL, "@");
	if(ret)
		printf("ret = %s\n", ret);
	
	ret = strtok(NULL, "");
	if(ret)
		printf("ret = %s\n", ret);
	
	ret = strtok(NULL, "");
	if(ret)
		printf("ret = %s\n", ret);

	return 0;
}

int _strchr(void)
{
	//ar str[32]={'s'};//这样写只是第一个为s,s后面是'\0',再后面没东西
	//mset(str, 'x', sizeof(str));//32个字符全部设为x,那'\0'放哪里的??
	
	//从左往右找,打印后面的
	char str[64] = "mv strfunc.c /home/jason/uc_study";
#if 0
	char *ret = strchr(str, 32);
	if(ret)
		printf("%s\n", ret+1); // strfunc.c /home/jason/uc_study 

	ret = strchr(ret+1, 32);
	if(ret)
		printf("%s\n", ret+1); // /home/jason/uc_study

#endif
	//从右往左找,打印后面的
	char *buf = strrchr(str, 32);
	if(buf)
		printf("%s\n", buf+1); // /home/jason/uc_study
	return 0;
}

int main(void)
{
	//_strtok();
	_strchr();
	return 0;
}
