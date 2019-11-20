#include <stdio.h>
#include <open_file.h>

int main(int args, char *argv[])
{
	char buf[128];

	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("open:");
		return -1;
	}

	int realise_read = read(fd, buf, 128);
	write(1, buf, realise_read);

	close(fd);
	return 0;
}
