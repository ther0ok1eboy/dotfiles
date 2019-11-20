#include <tcp_udp.h>

int main(void)
{

	char buf[128] = {0};
	socklen_t client_len;
	s_in4 serv ,client;
	//初始化serv成员
	serv.sin_family = AF_INET;		 //IPv4
	serv.sin_port = htons(4000);		 //端口号 4000
	serv.sin_addr.s_addr = htonl(INADDR_ANY);//通过服务器的任意地址即可连接

	//创建一个通讯接口
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1)
	{
		perror("socket");
		return -1;
	}

	//将通讯接口绑定到服务器的ip地址和端口号
	int bd = bind(fd, (s_in*)&serv, sizeof(serv));
	if(bd == -1)
	{
		perror("bind");
		return -1;
	}

	while(1)
	{
		client_len = sizeof(s_in4);

		//从客户端获取数据包存储到buf中,并将客户端的ip地址和端口号存储到结构体client
		memset(buf, 0, sizeof(buf));
		int rcv = recvfrom(fd, buf, 128, 0, (s_in*)&client, &client_len);
		if(rcv == -1)
		{
			perror("recvfrom");
			return -1;
		}
	
		//业务处理
		for(int i = 0; i < rcv; i++)
			buf[i] = tolower(buf[i]);

		//将处理结果发送给客户端
		int snd = sendto(fd, buf, rcv, 0, (s_in*)&client, sizeof(s_in4));
		if(snd == -1)
		{
			perror("sendto");
			return -1;
		}

	}

	return 0;
}
