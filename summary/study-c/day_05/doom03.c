#include <stdio.h>

int main()
{
	
	int arr[2][2] = {1,2,3,4};
	printf("arr[1]      %p\n", arr[1]);
	printf("arr[1][0]   %p\n\n", &arr[1][0]);

	printf("sizeof(arr[1]) %ld\n", sizeof(arr[1]));
	return 0;
}
