//使用man命令找函数的帮助信息

//man 1(command) 函数名(如printf)
//man 2(system call) 函数名
//man 3(library function) 函数名

#include <stdio.h>

int main()
{
	printf("hello world..\n");
	return 0;

}

//man.c ==预处理过程==> man.i ==编译==> man.s ==汇编==> man.o
//gcc -E man.c -o man.i
//使用预处理其(-E), 处理后输出为(-o)man.i 文件
//vi man.i将看到预处理器把stdio.h的内容复制了一份放在
//我们程序的开头,我们的程序在第800多行

//gcc -S man.i -o man.s(汇编文件)
//gcc -c man.s -o man.o(二进制文件)
//chmod a+x man.o(提升对man.o文件的操作的群星)
//man.o ==连接(动态/静态连接)库文件和系统提供的运行时文件==>a.out
//gcc man.o ==> a.out(可执行文件)
//
//gcc man.c ==> a.out (中间跨越了预处理 编译 汇编 连接)
