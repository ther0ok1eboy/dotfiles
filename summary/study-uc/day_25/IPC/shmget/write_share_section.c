#include <stdio.h>
#include <string.h>
//#include <open_file.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
	//获取一个键值
	key_t key = ftok(".", 25);
	if(key == -1)
	{
		perror("ftok");
		return -1;
	}
	printf("key:0x%x\n", key);

	//获取共享内存段的id,共享内存段不存在则创建,并设置权限
	int shmid = shmget(key, 1024, IPC_CREAT|0644);
	if(shmid == -1)
	{
		perror("shmget");
		return -1;
	}

	//将共享内存段关联到进程的地址空间,地址空间由内核选择,空间可读可写(0)
	void *p_shmat = shmat(shmid, NULL, 0);
	if(p_shmat == (void*)-1)
	{
		perror("shmat");
		return -1;
	}

	strcpy(p_shmat, "attach to share memory sucess...\n");
	getchar();

	//解除共享内存段和进程的关联
	shmdt(p_shmat);

	return 0;
}
