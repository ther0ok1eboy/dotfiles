#include <stdio.h>
#include <dlfcn.h>

int main(void)
{

	typedef int (*f_add)(int, int); //???

	//加载库文件
	void* p = dlopen("libdll.so", RTLD_NOW);
	if(NULL == p)
	{
		printf("%s\n", dlerror());
		return -1;
	}
	printf("open sucessfully...\n");

	//在dll中找函数并返回函数的地址
	void* f = dlsym(p, "add");
	//f 是函数add()的人口地址
	if(NULL == f)
	{
		printf("%s\n", dlerror());
		return -1;
	}
	//int (*f_add)(int, int) = f;
	printf("333 + 333 = %d\n",((f_add)f)(333, 333));

	//关闭动态库的加载
	dlclose(p);
	return 0;
}
