#include <stdio.h>

char *strcpy_(char *dest, const char *src)
{
	char *temp = dest;
	while(*src != '\0')
		*temp++ = *src++;
	//复制\0
	*temp = *src;
	return dest;
}

int main(void)
{
	char *src = "sucessfull...";
	//char *dest="0"; 段错误 bss区 数据不能更改
	char dest[16] = {0};
	strcpy_(dest, src);
	printf("%s\n", dest);

	return 0;
}
