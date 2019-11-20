#include<stdio.h>

int main()
{

	//method one:
	// 1 2 4 8 16 32 64 124 
	int num = 0;
	unsigned char ch = 0x80; // hex 128 bin 1000 0000
	printf("please input a intiger number(betwn 0-255)\n");
	scanf("%d",&num);

	/*
	printf("result :\n");
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;

	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf(" ");
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf("%d",(num & ch) != 0);
	ch = ch >> 1;
	
	printf("%d\n",(num & ch) != 0);
	ch = ch >> 1;

	*/

	//method two:
	printf("result :\n");
	for(int i = 0 ;i < 8 ;i++)
	{
		if(i == 4)
			printf(" ");	
		printf("%d",(num & ch) != 0);
		ch = ch >> 1;
	
	}
	printf(" ");	

	return 0;
	//  **** ****
	// &1000 0000
	//  0100 0000
	//  0010 0000
	//  ...
}
