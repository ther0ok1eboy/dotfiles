#include <stdio.h>

int main()
{

	char buf[32] = "helloworld";
	int num = 0;
	char ch = 'c';
	float fnum = 0.0f;

	//printf()会把内容转化为字符串再显示到屏幕上
	printf("%d %c %g\n", 34, 'y', 5.5f);
	//sprintf()会把内容转化为字符串放到buf中并覆盖其原来的内容
	sprintf(buf, "%d %c %g\n", 34, 'y', 5.5f);
	printf("sprintf() = %s", buf);//不用加\n,buf里已经有了

	//sscanf()会把括号前面的内容放后面的存储区
	char ssf[] = "10 C 5.5";
	sscanf(ssf, "%d %c %g", &num, &ch, &fnum);
	//sscanf("10 C 5.5", "%d %c %g", &num, &ch, &fnum);
	printf("%d %c %g\n", num, ch, fnum);

	return 0;
}
