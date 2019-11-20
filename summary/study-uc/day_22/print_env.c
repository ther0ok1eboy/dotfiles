#include <stdio.h>

int main01(void)
{
	extern char **environ;
	for(int i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return 0;
}

int main(int args, char *argv[], char *envp[])
{
	for(int i = 0; envp[i]; i++)
		printf("%s\n", envp[i]);

	return 0;
}
