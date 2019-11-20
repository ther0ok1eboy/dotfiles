#include <stdio.h>

void read_file()
{

	int write_arr[5][5] = {0};
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			write_arr[i][j] = i + 1;

	FILE* p_file = fopen("a.bin", "wb");
	//因为二维数组在存储区是连续的,所以可以填25
	fwrite(write_arr, sizeof(int), 25, p_file);

	/*也可以这样
	for(int i = 0; i < 5; i++)
		fwrite(write_arr[i], sizeof(int), 5, p_file);
	*/

	fclose(p_file);
	p_file = NULL;

}

void main(int args, char* argv[])
{
read_file();
}
