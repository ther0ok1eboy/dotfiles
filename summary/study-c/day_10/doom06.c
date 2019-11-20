#include <stdio.h>

int* change_ptr(int** pp_num)
{
	static int a = 100;
	*pp_num = &a;

	return *pp_num;
}

int main(int args, char** argv)
{
	//二级指针放一级指针的address
	char p = 'x';
	char q = 'y';
	char* pp = &p;
	char** P = &pp;

	//二级指针加*降级
	**P = 'X';
	printf("**P = %c\n", **P);
	*P = &q;
	printf("**P = %c\n", **P);

	//二级指针代表指针数组,不是代表二维数组
	//void* 是可以和一级指针捆绑在一起的
	//void* 与一级指针捆绑在一起的时候只有强转成二级指针才能使用
	
	char ch = 'c';
	char* p_ch = &ch;
	int num = 0;
	int* p_num = &num;
	float fnum = 5.5f;
	float* p_fnum = &fnum;

	void* p_void = &p_ch;
	printf("p_void = %c\n", **(char** )(p_void));
	p_void = &p_num;
	printf("p_void = %d\n", **(int** )(p_void));
	p_void = &p_fnum;
	printf("p_void = %g\n", **(float** )(p_void));
	//这样也可以
	p_void = &num;
	printf("p_void = %d\n", *(int* )(p_void));


	change_ptr(&p_num);
	printf("p_num = %d\n", *p_num);
	//只是改变了p_num的指向,num的值没变
	return 0;
}
