#include <stdio.h>

int* turn(int* p_arr, int len)
{
	int temp = 0;
	int* start = p_arr;
	int* end = p_arr + len -1;
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

	return p_arr;	
}

//我的方法写的:
void turn01(int* p_arr, int len)
{
        int temp = 0;
        for(int i = 0, j = len - 1; i < j; i++, j--)
        {
                temp = *(p_arr + i);
                *(p_arr + i) = *(p_arr + j);
                *(p_arr + j) = temp;
	}

}



int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	turn01(arr, 5);
	for(int i = 0; i < 5; i++)
		printf("%d ", *(arr + i));

	int *p_arr = turn(arr, 5);
	for(int i = 0; i < 5; i++)
                printf("%d ", *(p_arr + i));


	return 0;
}
