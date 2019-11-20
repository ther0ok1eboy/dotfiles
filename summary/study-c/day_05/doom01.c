#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int rand_num = 0;
	int num_array[7] = {0};

	for(int i = 0; i < 7; i++)
		num_array[i] = rand() % 35 + 1; // 1~36
	
	printf("your lottery is:\n");
	for(int i = 0; i < 7; i++)
		printf("%d ",num_array[i]);
	

	return 0;
}
