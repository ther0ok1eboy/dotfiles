#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

//caller define
typedef struct msgbuf
{
	long mtype;
        char mtext[128]; 
}msgbuf_t;

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
	//printf("key1:%d key2: %d\n", key1, key2);

	int msgflags = IPC_CREAT|0644;
	//使用key1获取消息队列的id
	int msgid = msgget(key1, msgflags);
	if(msgid == -1)
	{
		perror("msgget:");
		return -1;
	}
	printf("key1:0x%x\n", key1);
	//printf("msqid:%d\n", msqid);
	
	//初始化消息的内容
	msgbuf_t mbuf;
	memset(mbuf.mtext, 0, sizeof(mbuf.mtext));
	mbuf.mtype = 3; //must > 0
	strcpy(mbuf.mtext, "send sucessful...\n");

	//向消息队列发送消息
	int send = msgsnd(msgid, &mbuf, strlen(mbuf.mtext), 0);
	if(send == -1)
	{
		perror("msgsnd:");
		return -1;
	}
	
	return 0;
}
