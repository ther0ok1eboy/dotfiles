#include <stdio.h>
#include <unistd.h>

int main(void)
{
	alarm(5);//设置闹钟为5秒
	for(int i = 0; i < 900000; i++)
		printf("%d\n", i);

	//取消闹钟,将原来闹钟没有执行的时间返回
	int a = alarm(0);
	printf("%d\n", a); // 2
	return 0;
}
