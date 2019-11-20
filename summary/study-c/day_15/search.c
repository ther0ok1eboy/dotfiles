#include <stdio.h>

//顺序查找
//适用于数字之间没有任何规律
void bubble_sort(int* p_arr, int size)
{
	//TODO::
}

//折半查找
//适用于数字之间有一定顺序,一次排除一半
int* half_search(const int* p_arr, int size, int search_num)
{
	const int* begin = p_arr;
	const int* end = p_arr + size - 1;
	const int* mid = NULL;

	while(begin < end)
	{
		//这个中间位置画图好好理解一下
		mid = begin + ((end - begin + 1) / 2);

		if(*mid == search_num)
			return (int* )mid;
		else if(*mid > search_num)
			end = mid - 1;
		else
			begin = mid + 1;

	}
	
	return NULL;
}

int main()
{
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
	
	int* num = half_search(arr, 10, 2);
	printf("%d ", *num);
	return 0;
}
