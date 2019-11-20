#include <stdio.h>
#include <string.h>
#include <open_file.h>

int main(int args, char *argv[])
{
	char *buf = "named fifo sucess...\n";

	int fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		perror("open:");
		return -1;
	}

	write(fd, buf, strlen(buf));

	close(fd);
	return 0;
}
