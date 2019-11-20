#include <stdio.h>

//oxffffff5a ==> f/f/f/f/f/f/5/a ==> 8 bit binary
//0000 0000/0000 0000/0000 0000/...

void print(const int* p_arr, int size)
{

	for(int i = 0; i < size; i++)
		printf("%d ", *(p_arr + i));
	printf("\n");

}

void show(const void* p_num, int type)
{
	if(type == 0)
		printf("void* p_num = %c\n", *(const char* )p_num);

	if(type == 1)
		printf("void* p_num = %d\n", *(const int* )p_num);

	if(type == 2)
		printf("void* p_num = %g\n", *(const float* )p_num);

}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	int* p = arr;
	printf("arr     %p\n", arr);
	printf("arr + 2 %p\n", arr + 2);
	printf("arr[2]  %p\n", &arr[2]);
	printf("arr - 2 %p\n", arr - 2);
	
	const int* q = arr;
	//*p = 0; error
	int* const t = arr;
	//t = NULL; error
	
	void* k = arr;
	printf("*((int* )k + 1) =  %d\n", *((int* )k + 1));

	print(arr, 5);
	
	char ch = 'c';
	int num = 55;
	float fnum = 5.5f;
	show(&ch ,0);
	show(&num ,1);
	show(&fnum ,2);



	return 0;
}
