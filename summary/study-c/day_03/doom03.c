#include <stdio.h>

int main()
{
/*
	int num = 0;
	printf("please input an intiger \n");
	scanf("%d",&num);
	
	printf("|num| = ");
	if(num >= 0)
		printf("%d\n",num);
	else
		printf("%d\n",-num);

////////////////////////////////////////////////////////////////////////////

	int gender = 0;
	int weight = 0;
	int hight = 0;

	printf("please input your gender(0 1) weight and hight \n");
	scanf("%d %d %d",&gender,&weight,&hight);
	printf("tips:");

	if(gender == 0)
	{
		if(hight - weight < 110)
			printf("Mr. you are not outweight\n");
		else
			printf("Mr. you are outweight\n");
	
	}

	if(gender == 1)
	{
		if(hight - weight < 105)
			printf("Miss. you are not outweight\n");
		else
			printf("Miss. you are outweight\n");
	}

///////////////////////////////////////////////////////////////////////////////
	
	int year = 0;
	int month = 0;

	printf("please input year and month \n");
	scanf("%d %d",&year,&month);
	
	if(month == 1 || month == 3 ||
           month == 5 || month == 7 ||
           month == 8 || month == 10 ||
	   month == 12)	
		printf("this month has 31 days\n");

	if(month == 4 || month == 6 ||
	   month == 9 || month == 11)
		printf("this month has 30 days\n");

	if(month == 2)
	{
		if((year % 4 == 0 && year % 4 != 0) || year % 400 == 0)
			printf("this month has 29 days\n");
	
		else
			printf("this month has 28 days\n");
	}



	int num1,num2,num3;
	printf("please input three numbers\n");
	scanf("%d %d %d",&num1,&num2,&num3);

	int temp = num1;
	if(num2 > num1)
		temp = num2;
	if(num3 > temp)
		temp = num3;
	printf("the max among the three number is %d\n",temp);

////////////////////////////////////////////////////////////////////////////////
	
	printf("please input number(1-4)\n");
	int season = -1;
	scanf("%d",&season);
	
	printf("season is ");
	switch(season)
	{
		case 1: printf("spring\n");
			break;
		case 2: printf("summer\n");
			break;
		case 3: printf("autume\n");
			break;
		case 4: printf("winter\n");
			break;
		default: printf("unkowned\n");
			 break;
	}
*/
	printf("please input a date include year month and day\n");
	int year = 0, month = 0, day = 0, sum = 0;
	scanf("%d %d %d",&year, &month, &day);

	for(int i = month ;i > 1; i--)
	{
		if(i == 1 || i == 3 ||
        	   i == 5 || i == 7 ||
          	 i == 8 || i == 10 ||
	  	 i == 12)	
		sum += 31;

		if(i == 4 || i == 6 ||
	 	  i == 9 || i == 11)
		sum +=30;

		if(i == 2)
		{
			if(!(year % 4) && (year % 4) || !(year % 400))
				sum += 29;
		
			else
				sum += 28;
		}

	}

	printf("tatol days are %d\n",sum + day);
	return 0;
}


