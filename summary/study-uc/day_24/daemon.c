#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int args, char *argv[])
{
	//把进程设置为服务(精灵)进程
	daemon(0, 0);
	printf("%d\n", getpid());
	//设置自己的主目录为当前目录
	//chdir(getpwuid(getuid())->pw_dir);
	char ch = 'a';
	int flags = O_RDWR|O_CREAT;
	while(1)
	{
		int fd = open(argv[1], flags, 0644);
		if(++ch > 'z')
			ch = 'a';
		read(fd, &ch, 1);
		lseek(fd, 0, SEEK_SET);
		write(fd, &ch, 1);
		close(fd);
		sleep(3);
	}

	return 0;
}
