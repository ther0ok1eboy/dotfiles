#include <stdio.h>

// -D 命令可以决定宏名称代表的数字
//gcc -DPI=3.1415f(不能有空格) doom02.c
#define PI 3.1415f
#define SIZE 32
//gcc -DPI=3.1415f -DSIZE=5 doom02.c 处理多个的情况

#define ADD(x,y) ((x)+(y))
//编译器采用二次替换来处理代参宏
//不会为ADD()分配内存

#define ABS(n) /*表达式*/ ((n)>=0?(n):(-n))

//macro宏无法修改存储区的值
#define NEG(n) (2*(n))

//宏表达式不具有优先级 只是简单的宏替换 x - SUB(y)
//                          正确写法  x - (SUB(y))
//能当数用的建议用()阔起来
//不要把++ -- 当宏参数使用

//宏操作符:
//#:    #define STR(n) #n ==> "n"
//##:   #define PTR(n) p_##n ==> p_n

int abs(int num)
{
	return num >= 0 ? num : -num;
}

int main()
{
	printf("%g\n", PI);

	int arr[SIZE] = {0}; // SIZE为宏,处理要在预处理才能确定数组长度的情况

	char x = 'a', y = 'b';
	printf("add = %d\n", ADD(x, y));

	printf("ABS = %d\n", ABS(-80));
	
	int s = 10;
	printf(" %d\n", NEG(s));// 20
	printf("s = %d\n", s);  // 10










	return 0;
}
