#include "/home/jason/web_serve/include/web.h"

/*完成创建一个通讯端点和绑定本地ip的端口号工作*/
int socket_bind(int port) //port为自定义端口号
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

//***************************业务处理******************************//

//将客户端请求的首行信息分解到结构体变量的成员里
static void get_request(int cfd, request_t *reqst)
{
	char buf[512];
	int realise_read = read(cfd, buf, 512);
	sscanf(buf, "%s %s %s\r\n", reqst->method, reqst->path, reqst->protocol);
	
	//如果路径为/ ,则视为默认路径
	if(strcmp(reqst->path, "/") == 0)
		strcpy(reqst->path, "/index.html");

	return;
}

char *get_file_type(const char *path)
{

	if(strcmp(strrchr(path, '.'), ".jpg") == 0);
		return ".jpg";

	if(strcmp(strrchr(path, '.'), ".png") == 0);
		return ".png";
	
	//默认文件类型	
	return ".html";
}

//设置当前工作路径,让客户端只能访问html文件夹下的网页
char *reccent_dir = "/home/jason/web_serve/html";

static void get_file_path(respond_t *respd)
{

	char merge_path[128];
	memset(merge_path, 0, 128); //防止出现垃圾数据
	strcpy(merge_path, reccent_dir);
	strcat(merge_path, respd->rreqst->path); //在当前工作路径下拼接上客户端要请求的
						 //路径,方便cat命令直接访问本地服务器文件
	strcpy(respd->rreqst->path, merge_path); //再拷到响应路径
	
	return;
}

static void tackel_requst(respond_t *respd)
{
	/*获取路径里最后一个文件的类型*/
	respd->file_type = get_file_type(respd->rreqst->path);

	/*获取请求文件在服务器里路径的位置*/
	get_file_path(respd);

	/*获取响应码code 404 200*/
	//判断请求文件文件是否可读(0可读,-1不可读)
	respd->code = access(respd->rreqst->path, R_OK) ? 404 : 200;	

	return;
}

static void response_brower_200(int cfd, respond_t *respd)
{
	char first_line[128];
	char content[128];
	//按网页协议格式输入
	sprintf(first_line, "%s %d\r\n", respd->rreqst->protocol, respd->code);
	sprintf(content, "Content-Type: %s\r\n\r\n", respd->file_type);

	//输出到通讯端口cfd
	write(cfd, first_line, strlen(first_line));
	write(cfd, content, strlen(content));

	//将输出设备重定义为通讯端口cfd,cat命令打开客户端请求文件将会输入到cfd
	dup2(cfd, 1);
	//此时respd->rreqst->path里的路径是客户端要请求的文件在本地服务器的位置
	execlp("cat", "cat", respd->rreqst->path, NULL);

	return;
}

static void response_brower_400(int cfd)
{
	char *buf = "Error404: Not Found The File....";
	write(cfd, buf, strlen(buf));
	return;
}

static void response_brower(int cfd, respond_t *respd)
{
	if(respd->code == 200)
		response_brower_200(cfd, respd);
	else if(respd->code == 404)
		response_brower_400(cfd);

	return;
}

int handle_business(int cfd)
{
	request_t reqst;
	respond_t respd;
		
	/*获取客户端的请求*/
	get_request(cfd, &reqst);
	
	/*根据客户端请求信息处理信息*/
	respd.rreqst = &reqst;
	tackel_requst(&respd);
	
	/*根据处理结果响应客户端*/
	response_brower(cfd, &respd);
	
	return 0;

}

