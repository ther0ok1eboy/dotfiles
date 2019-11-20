#include <stdio.h>

int abs(int val)
{
	return val >= 0 ? val : -val;
}

//call back function:
void for_each(int* p_arr){ printf("%d ", - *p_arr); }

void print(int* p_arr, int size, void (*p_for_each)(int* ))
{
	//void (*p_for_each)(int* ) = for_each;
	for(int i = 0; i < size; i++)
		p_for_each(p_arr + i);

}

int main()
{
	int a[10];
	int* b[10];   //??
	int (*c)[10]; //??
		
	printf("&abs = %p\n", abs);

	int (*p_abs)(int) = NULL;
	p_abs = abs; // 可与不同函数进行绑定
	printf("p_abs() = %d\n", p_abs(-9));

	int arr[5] = {1, 3, 5, 4, 2};
	print(arr, 5, for_each);
	return 0;
}
