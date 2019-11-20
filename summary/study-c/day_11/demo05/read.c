#include <stdio.h>

void main(int args, char* argv[])
{

	int read_arr[5][5] = {0};
	FILE* p_file = fopen("a.bin", "rb");
	//fread(read_arr, sizeof(int), 25, p_file);
	for(int i = 4; i >= 0; i--)
		fread(read_arr[i], sizeof(int), 5, p_file);
	
	fclose(p_file);
	p_file = NULL;


	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
			printf("%d ", read_arr[i][j]);
		printf("\n");
	}

}
