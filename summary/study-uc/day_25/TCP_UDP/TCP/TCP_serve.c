/*
 *服务器端负责将客户端发送过来的字符串转换为大写
 * */

#include <TCP.h> //放在 /usr/include下

int main(void)
{
	s_in4 client; //具体
	unsigned int zombie_pid[128] = {0};

	int lfd = socket_bind(1024);
	if(lfd == -1)
		return -1;
	
	//将lfd设置为被动连接模式,监听客户端连接的到来,如果有客户端的连接到来,将该连接放入未决连接队列中
	//将未决连接队列长度设置为5
	listen(lfd, 5);
	
	int i = 0;
	while(1)
	{
		socklen_t client_len = sizeof(client);

		//从未决连接队列中取出第一个连接进行处理,如果未决连接队列里没有数据,阻塞等待,有就返回一个文件描述符
		//int cfd = accept(lfd, NULL, NULL);
		//将客户端的ip地址和端口号保持到client这个结构体中
		int cfd = accept(lfd, (s_in*)&client, &client_len);
		if(cfd == -1)
		{
			perror("accept");
			return -1;
		}
			
		//把连接过服务器的客户端的ip地址显示出来
		//binart ==> text
		char client_ip[64];
		printf("%s 客户端已连接...\n", inet_ntop(AF_INET, &client.sin_addr, client_ip, 64));

		pid_t pid = fork();
		if(pid == -1)
		{
			perror("fork");
			return 0;
		}
		if(pid == 0)
		{
			//关闭lfd
			close(lfd);			
			//处理具体客户端请求
			socket_operator(cfd);
			//将子进程pid记录到数组中
			zombie_pid[i] = getpid();
			//关闭cfd
			close(cfd);
			//退出进程
			exit(0);
		}
		else
		{
			//在未决连接队列中取出一个lfd
			//创建子进程

			//关闭cfd,非阻塞
			close(cfd);

			waitpid(-1, NULL, WNOHANG);
		}


			int count = 0;
			while(zombie_pid[count])
			{
				kill(zombie_pid[count], 17);
				zombie_pid[count] = 0;
				count++;
			}
	}

	return 0;
}
