#include <TCP.h>

int socket_bind(int port)
{	
	s_in4 serv;

	//初始化serv成员
	serv.sin_family = AF_INET;   //IPv4
	serv.sin_port = htons(port); //设置端口并转换为网络字节序
	//INADDR_ANY代表本机的所有ip地址,并转换为网络字节序
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	//创建一个socket,返回socket的文件描述符lfg,IPv4,protocol为0
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	if(lfd == -1)
	{
		perror("socket");
		return -1;
	}

	//将lfd绑定到服务器(local)的ip地址和端口号,强转为一般
	int b = bind(lfd, (s_in*)&serv, sizeof(serv));
	if(b == -1)
	{
		perror("bind");
		return -1;
	}

	return lfd;
}


int socket_operator(int cfd)
{

	char buf[128];

	while(1)
	{
		memset(buf, 0, sizeof(buf));
		//这时候,三次握手已经能成功
        	//读取客户端的请求
      		int realise_read = read(cfd, buf, 128);
        
		//处理客户端的请求
 	      	for(int i = 0; i < realise_read; i++)
       			buf[i] = toupper(buf[i]);

		//响应客户端,将处理结果响应给客户端
	        write(cfd, buf, realise_read);

		//如果处理后的字符串为EXIT,先发送给客户端再处理下一个连接
		if(!strcmp(buf, "EXIT\n"))
		{
			printf("已退出...\n");
			break;
		}
	}
	
	return 0;

}

