#ifndef _TCP_UDP_H_
#define _TCP_UDP_H_

/*头文件包含*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ctype.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

/*类型声明*/
typedef struct sockaddr_in s_in4;
typedef struct sockaddr s_in;

//请求的首行信息结构体
typedef struct
{
	char method[32];     //GET
	char path[128];      //客户端请求路径
	char protocol[16];   //HTTP/1.1

}request_t;

//响应客户端的结构体
typedef struct
{
	int code; 	     //响应的编码 404 200
	char *file_type;     //请求路径里文件的类型
	request_t *rreqst;

}respond_t;

/*函数声明*/
int socket_bind(int port);   /*完成socket()和bind()并返回lfd文件描述符*/
int handle_business(int cfd); /*处理客户端的请求*/

#endif //_TCP_UDP_H_
