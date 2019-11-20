/*
 *客户端端负责向服务器发送字符串
 * */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>

int main(int args, char *argv[])
{

	if(0 == argv[1])
	{
		printf("please input serve ip...\n");
		return -1;
	}

	struct sockaddr_in serv; //这是服务器的ip地址和端口号
	char msg[128];
	char buf[128];

	//初始化serv成员
	serv.sin_family = AF_INET;
	serv.sin_port = htons(1024);

	//服务器(本机)的ip地址192.168.230.144 text ==> binary 并将转换结果存放到serv.sin_addr中
	//inet_pton(AF_INET, "192.168.230.144", &serv.sin_addr);
	inet_pton(AF_INET, argv[1], &serv.sin_addr);

	//创建一个socket,返回socket的文件描述符fg,IPv4,protocol为0
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1)
	{
		perror("socket");
		return -1;
	}

	//使用fd向服务器发起连接,成功则三次握手成功
	int cnct = connect(fd, (struct sockaddr*)&serv, sizeof(serv));
	if(cnct == -1)
	{
		perror("bind");
		return -1;
	}

	while(fgets(msg, 128, stdin)) //fgets()不满时末尾为'\n',满时清缓存
	{	
		//向服务器发送字符串
		write(fd, msg, strlen(msg));

		//等待服务器的响应,如果没有响应阻塞等待
		memset(buf, 0, sizeof(buf));
		int realise_read = read(fd, buf, 128);
		
		//输入exit后,发送exit给服务器的时候再断开连接
		if(!strcmp(buf, "EXIT\n"))
			break;

		//将获取到的响应信息输出到显示器
		write(1, buf, realise_read);
	}	
	//关闭和服务器的连接,结束通讯
	close(fd);
		
	return 0;
}
