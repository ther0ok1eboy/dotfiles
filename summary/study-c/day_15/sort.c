#include <stdio.h>

//把一个数像冒泡一样冒泡到最后
void bubble_sort(int* p_arr, int size)
{
	int temp = 0;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(p_arr[j] > p_arr[j + 1])
			{
				temp = p_arr[j + 1];
				p_arr[j + 1] = p_arr[j];
				p_arr[j] = temp;
			}
		}
	}

	for(int i = 0; i < size; i++)
		printf("%d ", p_arr[i]);
}

//先确定位置再找位置,把选好的数字插到合适的位置
void insert_sort(int* p_arr, int size)
{
	int temp = 0;
	for(int i = 1; i < size; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(p_arr[i] < p_arr[j])
			{
				temp = p_arr[i];
				p_arr[i] = p_arr[j];
				p_arr[j] = temp;
			}
		}
	
	}
	
	for(int i = 0; i < size; i++)
		printf("%d ", p_arr[i]);

/**************************效率更高**********************
	int temp = 0;
	for(int i = 1; i < size; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(p_arr[j + 1] < p_arr[j])
			{
				temp = p_arr[j + 1];
				p_arr[j + 1] = p_arr[j];
				p_arr[j] = temp;
			}
			//因为前面已经排好序,不需要一个个的对比
			else
				break;
		
		}
	}
		for(int i = 0; i < size; i++)
			printf("%d ", p_arr[i]);

***************************************************/	
}

void quick_sort(int* p_arr, int size)
{
	if(size <= 1)
		return;

	//选第一个位置作为基点
	int base = p_arr[0];
	int temp = 0;
	int* begin = p_arr;
	int* end = p_arr + size - 1;

	//找到一个数,数的左边一部分,右边一部分
	while(begin < end)
	{
		if(*begin > *end)
		{
			temp = *begin;
			*begin = *end;
			*end = temp;
		}

		//交换位置,画图理解
		if(*begin == base)
		{
			end--;
		}
		else
		{
			begin++;
		}
	
	}

	//p_arr始终是指向数组第一个的指针
	//这个时候找到的中间的数就算*begin
	//两个相减即位size
	quick_sort(p_arr, begin - p_arr);
	quick_sort(begin + 1, size - (begin - p_arr) - 1 /* 这个1是减去*begin */);
}

int main()
{
	int arr[10] = {3,2,5,4,1,9,0,6,8,7};
	//bubble_sort(arr, 10);
	
	//insert_sort(arr, 10);
	
	quick_sort(arr, 10);
	for(int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}
