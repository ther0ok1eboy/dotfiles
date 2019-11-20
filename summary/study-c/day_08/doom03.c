#include <stdio.h>
#include <string.h>

int atoi(const char* p_buf)
{
	int result = 0;
	while(*p_buf >= '0' && *p_buf <= '9')
	{
		result = result * 10 + (*p_buf - '0');
		p_buf++;
	}

	return result;
}

char* read(void)
{
	//键盘录入int数据，用字符串输出
	int num = 0;
	char temp[8] = {0};
	static char arr[32] = {0};
	while(1)
	{
		scanf("%d", &num);
		if(num >= 0 && num <= 100)
		{
			sprintf(temp, "%d,", num);
			strcat(arr, temp);
		}
		else
			break;
	}
	arr[strlen(arr) - 1] = '\0';
	return arr;

}


int main()
{
	
	//提示:
	printf("%d\n", '3' - '0'); // 3

	char buf[32] = {0};
	printf("please input a string\n");

	fgets(buf, 32, stdin);
	if(strlen(buf) == 31 && buf[30] != '\n')
	{
		scanf("%*[^\n]");
		scanf("%*c");
	
	}

	printf("atoi(buf) = %d\n", atoi(buf));
	
	
	char* p_num = read();
	printf("%s\n" ,p_num);



	return 0;
}
