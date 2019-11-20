#include <stdio.h>
#include <signal.h>
#include <unistd.h>

unsigned int sleep_(unsigned int seconds)
{
	//设置闹钟为seconds秒
	alarm(seconds);
	//进程停下来等待信号到达
	pause();
	//将剩余没有执行的时间返回
	return alarm(0);
}

void hold(int sig_num){return;}

int main(void)
{
	//在SIGALRM信号抵达的时候不然进程死掉
	signal(SIGALRM, hold);
	int i = 0;
	while(1)
	{
		sleep_(1);
		printf("sucess...%d\n", i);
		i++;
	}
	return 0;
}
