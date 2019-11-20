//#include"stdio.h"       // 先在当前目录找，再到系统目录找
#include<stdio.h>         // 以系统中预先规定好的一组目录作为起点

int main()
{
	printf("HelloWorld\n");
	printf("My first c program on Ubuntu call sucessfully!!\n");
	return 0;        //主函数退出，并告诉系统正常推出
}

//program compile step:
//under current diri
//gcc HolleWorld.c ==> a.out
//./a.out ==> result

//gcc work principle:
//deal with pre_order
//turn the result of first into format that computer can recognize
//merge the result of second a .out file

//gcc some functions:
//gcc -E only do pre_order
//gcc -c only do pre_order and compile ==> .o target file
//gcc -o decide the name of a.out
//gcc -std=c89 (defualt) / -std=c99 compile with c89 or c99
