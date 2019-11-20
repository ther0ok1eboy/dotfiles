#include <stdio.h>

int* find_max(int* p_arr, int len)
{
	int* max = p_arr;
	for(int* p_temp = p_arr; p_temp < p_arr + len; p_temp++)
	{
		if(*max < *p_temp)
			max = p_temp;
	}
	return max;

	/*我一般会这样写:
	int* max = arr;
	for(int i = 1; i < len; i++)
	{
		if(*m < arr[i])
			max = &arr[i];
	}
	return max;
	*/
}

int main()
{
	
	int arr[5] = {1, 2, 9, 0, 7};
	int* p_num = find_max(arr, 5);
	printf("p_num = %d\n,", *p_num);
	
	
	
	return 0;
}
