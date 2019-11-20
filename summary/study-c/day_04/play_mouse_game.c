
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int num = 0, bingo_count = 0, x= 0, y = 0, ppos = 0;
	printf("what is time you want to play\n");
	scanf("%d",&num);
	
	printf("the initializition is\n");
	printf("* * *\n");
	printf("* * *\n");
	printf("* * *\n");

	for(int i = 0; i < num; i++)
	{	
	
		printf("please input the position (1,1)\n");
		scanf("%d %d",&x, &y);
		
		if((x < 1 || x >3) || (y < 1 || y > 3))
		{
			printf("position error!!\n");
			return 0;
		}

		//record player position
	 	if(x == 1)
			ppos = y;
		if(x == 2)
			ppos = 3 + y;
		if(x == 3)
			ppos = 6 + y;
		
		//record mouse position
		int mpos = rand() % 9 + 1;
		if(mpos == ppos)
		bingo_count++;

		for(int i = 1; i <= 9; i++)
		{
			
			if(i == ppos || i == mpos)
			{
				if(i == ppos && i == mpos)
				printf("X ");
				else
				{
					if(i == ppos)
					printf("0 ");
					else
					printf("x ");
				}

			}
			
			else
				printf("* ");

			if(i % 3 == 0)
				printf("\n");
		
		}
	
	}

	printf("0 is your position and x is mouse's position\n");
	printf("your bingo count is %d\n",bingo_count);

	return 0;
}
