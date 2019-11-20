#include <stdio.h>
#include <stdlib.h>

void rabbit_chicken(int args, char* argv[])
{

	int head = atoi(*(argv + 1));
	int leg = atoi(*(argv + 2));

	for(int i = 0; i <= head; i++)
	{
		if(4 * i + 2 * (head - i) == leg)
		{
		printf("rabbit have %d chicken have%d\n", i, head - i);
		break;
		}
	
	}

}

int main(int args, char* argv[])
{
	char* parr[] = {"ab", "cd", "ef"};
	for(int i = 0; i < 3; i++)
		printf("%s ", *(parr + i));

	rabbit_chicken(args, argv);

	
	return 0;
}
