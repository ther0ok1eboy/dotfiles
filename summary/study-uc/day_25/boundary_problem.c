#include <stdio.h>
#include <pthread.h>

int globle_val;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *thread(void *argv)
{
	int local_val;

	//解锁
	//pthread_mutex_lock(&mutex);
	//锁加在这个位置相当于还是单线程在操作
	for(int i = 0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex);
		
		local_val = globle_val;
		local_val++;
		printf("local_val %d\n", local_val);
		globle_val = local_val;
		
		pthread_mutex_unlock(&mutex);
	}
	//解锁
	//pthread_mutex_unlock(&mutex);

	return (void *)1;
}

int main(void)
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, thread, NULL);
	pthread_create(&tid2, NULL, thread, NULL);
	
	//等待线程汇合
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	//释放mutex锁
	pthread_mutex_destroy(&mutex);
	return 0;

}
