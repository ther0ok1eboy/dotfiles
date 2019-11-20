#include<stdio.h>

int main()
{

int gender = 0;
int weight = 0; 
int height = 0;

printf("please input the gender weight and height\n");
scanf("%d %d %d",&gender,&weight,&height);

// method one:
/*
if(gender == 0)
{
 if(height - weight < 105)
 	printf("Mr. you are out weight\n");
 else
        printf("Mr. you are weight\n");
}

if(gender == 1)
{
 if(height - weight < 110)
	printf("Miss. you are out weight\n");
 else
 	printf("Miss. you are out weight\n");
}
*/

//method two:
int ret = gender ? height - weight < 105 : height - weight < 110;

if (ret == 1)
 	printf("Mr. you are out weight\n");
if(ret == 0)
 	printf("Miss. you are not out weight\n");

return 0;
}

