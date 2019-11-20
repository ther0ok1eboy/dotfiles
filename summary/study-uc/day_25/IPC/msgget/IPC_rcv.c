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
	if(msqid == -1)
	{
		perror("msgget:");
		return -1;
	}
	printf("key1:0x%x\n", key1);
	//printf("msqid:%d\n", msqid);
	
	//初始化mbuf
	msgbuf_t mbuf; //可以和发送时的结构体的名字不一样
	memset(mbuf.mtext, 0, sizeof(mbuf.mtext));
	//mbuf.mtype = 3; //must > 0 发送3类型的消息也要用3类型接收

	//向消息队列读取消息放mbuf.mtext中,没有消息就阻塞
	//int rcv = msgrcv(msqid, &mbuf, 128, 3, 0);
	//向消息队列读取消息放mbuf.mtext中,没有消息不阻塞,报错
	int rcv = msgrcv(msgid, &mbuf, 128, 3, IPC_NOWAIT);
	if(rcv == -1)
	{
		perror("msgsnd:");
		return -1;
	}
	printf("%s", mbuf.mtext);
	return 0;
}
