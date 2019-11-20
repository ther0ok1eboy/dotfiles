#include <stdio.h>

//echo string 把string显示到屏幕
//$? 上一个进程的返回结果
//echo $?

//nm binnary file (看二进制文件里面的符号表)
//T U(undefine) 函数    b 数据  前面的地址在link的时候会被重新定位
//file binary file 会看到 LSB relocatable
//中间那一大陀是运行时文件
//gcc a.o -v 可以看见很多在link阶段的.o运行时文件

//gcc a.o
//静态连接
//link发生在*.o ==> *.out 之间,可执行文件还没执行阶段

//gcc a.o -v 看link阶段信息
//chmod a+x /usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o
//nm /usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o
//看到T _start 而 U main
//程序入口是_start,它调用main， C函数入口是main函数
//运行时文件就算一个写好的一大堆.o file
int add(int a, int b)
{
	return a + b;
}

int main(void)
{	
	int a = 1, b = 1;
	printf("nm + binary file");
	add(a, b);
	return 0;
}
