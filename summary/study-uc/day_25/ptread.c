#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *newthread(void *argv)
{
	//相同的pid,不同的tid
	printf("%s\t pid:%d\t uid:%lu\n", (char *)argv, getpid(), pthread_self());
	return NULL;
}

void *thread1(void *argv)
{
	printf("thread1 running...\n");
	return (void *)66;
}

void *thread2(void *argv)
{
	printf("thread2 running...\n");
	pthread_exit((void *)6);
}

void *thread3(void *argv)
{
	while(1)
	{
		printf("thread3 running...\n");
		sleep(1);
	}
}

int main(void)
{
	pthread_t tid;
#if 0
	pthread_create(&tid, NULL, newthread, "thread: newthread()...");
	sleep(1);
	newthread("main: newthread...");
#endif
	void *tret;

	pthread_create(&tid, NULL, thread1, NULL);
	//阻塞等待线程汇合,将汇合后线程的退出状态获取
	//将thread1线程的退出状态存储到tret中
	pthread_join(tid, &tret);
	printf("exit status of thread1 %d\n",(int)tret);

	pthread_create(&tid, NULL, thread2, NULL);
	pthread_join(tid, &tret);
	printf("exit status of thread2 %d\n", (int)tret);
	
	pthread_create(&tid, NULL, thread3, NULL);
	sleep(3);
	//给thread3 发送取消请求
	pthread_cancel(tid);
	pthread_join(tid, &tret);
	printf("exit status of thread3 %d\n", (int)tret);
	return 0;

}

// link with -lpthread
