#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[64];
	int age;
}memc;

//任何数据都能拷贝,且不易造成数据溢出
void memcpy_()
{
	/*
       	memcpy - copy memory area
       	#include <string.h>
       	void *memcpy(void *dest, const void *src, size_t n);
	*/

	memc mc;
	memset(mc.name, 0, sizeof(mc.name));
	strcpy(mc.name, "sorria");
	mc.age = 19;
	printf("mc:%s %d\n", mc.name, mc.age);

	memc cpy_mc;
	memcpy(&cpy_mc, &mc ,sizeof(mc));
	printf("cpy_mc:%s %d\n", cpy_mc.name, cpy_mc.age);

	char name[32];
	char *p_name = NULL;
	//把最后的'\0'也拷贝进去
	p_name = memcpy(name, mc.name, strlen(mc.name) + 1);
	printf("name:%s\n", name);
	printf("p_name:%s\n", p_name);
}

//只能拷贝字符串,不要长度参数,拷贝以'\0'结束,易造成数据溢出
void strcpy_()
{
	/*
       	strcpy, strncpy - copy a string
       	char *strcpy(char *dest, const char *src);
       	char *strncpy(char *dest, const char *src, size_t n);
	*/
}

int main(void)
{
	memcpy_();
	return 0;
}
