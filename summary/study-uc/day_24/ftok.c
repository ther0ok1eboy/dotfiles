#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main(void)
{
	//获取一个键值
	key_t key1 = ftok(".", 1); //低有效8位
	key_t key2 = ftok(".", 257);
	if(key1 == -1 || key2 == -1)
	{
		perror("ftok:");
		return -1;
	}
	printf("key1:%d key2: %d\n", key1, key2);

	int msgflags = IPC_CREAT|0644;
	//使用key1获取消息队列的id
	int msqid = msgget(key1, msgflags);
	if(msqid == -1)
	{
		perror("msgget:");
		return -1;
	}
	printf("key1:0x%x\n", key1);
	printf("msqid:%d\n", msqid);
	return 0;
}
