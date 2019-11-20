#include <stdio.h>
#include <stdlib.h>

int read(void)
{
	char arr[50] = {0};
	char* p_arr = arr; 
	int sum = 0;
	printf("please input a string number(1,2,3..)\n");
	fgets(arr, 50, stdin);
	while(*p_arr)
	{
		sum += atoi(p_arr);
		p_arr++;

	}

	return sum;
}

int main()
{

	char* str[] = {"ab", "cde", "e", "ffffffffff"};
	int a = 5;
	sizeof(str);        //4*8 = 32
	sizeof(a = 5.5555); //4

	printf("read() = %d\n", read());
	return 0;
}
