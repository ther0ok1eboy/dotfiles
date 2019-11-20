#include <stdio.h>

int main(void)
{
	int num1 = 0, num2 = 0, num3 = 0, temp = 0;
	printf("all the results which are water_flower number betewn 100 to 1000:\n");
	for(int i = 100; i <= 1000; i++)
	{
		temp = i;
		num1 = temp % 10; //ge wei shu
		temp = temp / 10;
		num2 = temp % 10; //shi wei shu
		num3 = temp / 10; //bai wei shu

		if(num1 * num1 * num1 +
		   num2 * num2 * num2 +
		   num3 * num3 * num3 == i)
		printf("%d\t",i);

	}


	return 0;
}
