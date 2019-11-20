#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char buf[16] = "helloworld";

	//atoi()将开头字符串里面的数字字符转化为数字	
	printf("5bdc = %d\n", atoi("5bcd"));
	printf("545 = %d\n", atoi("545"));

	//atof() 和atoi()类似，转化为双精度	
	printf("5.5bdc = %lg\n", atof("5.5bcd"));

	//如果输入的字符串超过了数组的长度，后果严重
	printf("please input a string\n");
	//scanf("%s", buf); //input abc bcd ==> printf abc
	printf("buf = %s\n", buf);

	fgets()可避免scanf()的问题
	printf("please input a string again\n");
	//fgets(buf, 16, stdin); 
	//如果输入过多，则会把多余的留在缓冲区让下次读取
	//如果输入的内容不能把数组充满，则会把用户最后输入的换行也读进取
	printf("buf = %s\n", buf);
	//只有确定缓冲区包含多余数据才应该使用下面两句
	//否则当输入的数据不能填满数组的时候会有问题？？
	//通过判断数组中是否有'\n'来确定缓冲区是否有数据
	if(strlen(buf) == 16 - 1 && buf[16 - 1 - 1] != '\0') //自己想想为什么
	{
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return 0;
}
