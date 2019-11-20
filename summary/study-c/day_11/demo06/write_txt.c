#include <stdio.h>
#include <string.h>

int main(int args, char* argv[])
{
	char buf_arr[16] = {0};
	int arr[] = {1, 22, 333, 4444, 55555};
	FILE* p_file = fopen("a.txt", "wb");
	if(!p_file){return 0;};

	printf("sizeof(arr) = %ld\n", sizeof(arr)); // 20	
	//把数组元素写进文本文件里:
	for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		sprintf(buf_arr, "%d ", arr[i]);
		fwrite(buf_arr, sizeof(char), strlen(buf_arr), p_file);
	}

	fclose(p_file);
	p_file = NULL;
	
	//p_file = fopen("a.txt", "rb");
	//如读文本文件就不容易,因为其格式千差万别,不像bin文件其格式比较固定
	
	
	return 0;
}
