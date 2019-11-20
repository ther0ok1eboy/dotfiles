#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void change_sigin(int signal_num)
{
	printf(" signal %d has been changed...\n", signal_num);
}

int main01(void)
{
	//设置进程忽略2号信号(ctrl c)
	//signal(2, SIG_IGN);
	//设置进程忽略3号信号(ctrl \)
	//signal(3, SIG_IGN);
	//设置进程忽略9号信号(不能被忽略)
	//signal(9, SIG_IGN);
	//自定义信号处理函数
	signal(2, change_sigin);
	while(1);
	return 0;
}

int main02(void)
{
	//定义信号集类型变量
	sigset_t sigset;
	//初始化信号集为空
	sigemptyset(&sigset);
	//把2号和3号信号添加到信号集sigset中
	sigaddset(&sigset, 2);
	sigaddset(&sigset, 3);

	//测试9号信号是否为sigset集合的成员
	int ret = sigismember(&sigset, 9);
	if(ret == -1)
	{
		printf("call sigismember error...\n");
		return -1;
	}
	ret ? printf("yes it is...\n") : printf("no it it not...\n");

	return 0;
}

//使用sigprocmask()让进程对2号信号的屏蔽
int main03(void)
{

	sigset_t set;
	//填充所有的信号
	sigfillset(&set);

	//使用自己的set信号集,并不保存原来的信号
	sigprocmask(SIG_SETMASK, &set, NULL);
	while(1);
	return 0;
}

void hold(int signum)
{
	printf("%d signal call...\n", signum);
}
int main04(void)
{
	//把2号和45号设置为自定义信号
	signal(2, hold);
	signal(45, hold);

	sigset_t set, oldset;
	sigemptyset(&set);
	//2 45 加入信号集
	sigaddset(&set, 2);
	sigaddset(&set, 45);

	//设置对2号和45号信号的阻塞,并保存原来的信号屏蔽字到oldset中
	sigprocmask(SIG_SETMASK, &set, &oldset);
for(int i = 0; i < 10000000; i++)
	{
		printf("%d\n", i);
	}
	
	//恢复原来的信号屏蔽字,解除对2 45号的阻塞
	sigprocmask(SIG_SETMASK, &oldset, NULL);

	return 0;
}

int main(void)
{
	sigset_t set, pending_set;
	sigemptyset(&set);
	sigaddset(&set, 2);
	//设置进程的信号掩码为set
	sigprocmask(SIG_SETMASK, &set, NULL);
	while(1)
	{
		sleep(2);
		//获取进程的未决信号并放pending_set中
		sigpending(&pending_set);
		//检测2号信号是pending_set信号集的成员
		int ret = sigismember(&pending_set, 2);
		if(ret == -1){printf("sigmember() call error...\n");return -1;}
		ret ? printf("yes it is..\n") : printf("no it is not..\n");
	}

	return 0;
}

