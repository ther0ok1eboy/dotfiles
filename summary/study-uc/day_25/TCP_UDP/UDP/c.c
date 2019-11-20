#include <tcp_udp.h>

int main(int args, char *argv[])
{
	if(!argv[1])
	{
		printf("please input serve address...\n");
		return -1;
	}

	char buf[128] = {0};
	char msg[128] = {0};
	s_in4 serv;
	//初始化serv成员
	serv.sin_family = AF_INET;		 //IPv4
	serv.sin_port = htons(4000);		 //端口号 4000
	inet_pton(AF_INET, argv[1], &serv.sin_addr);

	//创建一个通讯接口
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd == -1)
	{
		perror("socket");
		return -1;
	}

	while(fgets(msg, 128, stdin))
	{	
		
		int snd = sendto(fd, msg, strlen(msg), 0, (s_in*)&serv, sizeof(s_in4));
		if(snd == -1)
		{
			perror("sendto");
			return -1;
		}

		memset(buf, 0, sizeof(buf));
		int rcv = recvfrom(fd, buf, 128, 0, NULL, NULL);
		if(rcv == -1)
		{
			perror("recvfrom");
			return -1;
		}
		
		if(!strcmp(buf, "exit\n"))
			break;

		write(1, buf, rcv);
	}

	return 0;
}
