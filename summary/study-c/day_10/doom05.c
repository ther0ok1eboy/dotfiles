#include <stdio.h>

typedef union person /*P*/
{
	char name[32];
	char sex;
	int age;

}P;

int main()
{
	enum ENUM{a , b, c, e, f, g}Enum;
	printf("%d\n", b); // 1

//	enum {a = 9, b, c, d};//ENUM可丢 一般这样写
//	printf("%d\n", b); // 9
//	无论里面有多少个枚举,sizeof()都是 4 
	printf("sizeof(Enum) = %ld\n", sizeof(enum ENUM)); // 4 或着sizeof(Enum) = 4
	
	
	
	//union 每个存储区是重叠的,地址一样
	P p = {12}; //每次怎能初始化一个变量,整个union当这个变量用
	printf("p.sex = %p\n", &p.sex);//0x7ffdb105fe30
	printf("p.age = %p\n", &p.age);//0x7ffdb105fe30
	printf("sizeof(p) = %ld\n", sizeof(p)); //32 最大子存储区的大小
	
	return 0;
}
