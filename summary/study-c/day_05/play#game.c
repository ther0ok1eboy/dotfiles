#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{

	srand(time(NULL));
	int row = 0, col = 0, i = 0;
	char player = 'o';   //x代表电脑
	char map[3][3];

	//初始化地图
	for(row = 0; row < 3; row++)
		for(col = 0; col < 3; col++)
			map[row][col] = '*';	
	printf("* * *\n* * *\n* * *\n");

	for(i = 0; i < 9; i++)
	{
		if(player == 'o')
		printf("%c please input your position(1,1)\n", player);
		//判断输入坐标是否有效，无效则重新输入
		while(1)
		{
			if(player == 'o')
			scanf("%d %d", &row, &col);
			else
			{
				row = rand() % 3 + 1;
				col = rand() % 3 + 1;
			}


			if(row < 1 || row > 3)
			
				continue;
			if(col < 1 || col > 3)	
				continue;

			//位置重合的时候
			if(map[row - 1][col- 1] != '*')
				continue;
			
			break;

		}
	
		map[row - 1][col - 1] = player;

	//刷新地图
	printf("-----------------------------------------\n");
	for(int row = 0; row < 3; row++)
	{
 		for(int col = 0; col < 3; col++)
			printf("%c ", map[row][col]);
		printf("\n");
	}

	//判断是否有胜利者
	if(map[0][0] != '*' && map[0][0] == map[0][1] && map[0][1] == map[0][2])
	{
		printf("winner is %c\n", map[0][0]);
		break;
	}
	if(map[1][0] != '*' && map[1][0] == map[1][1] && map[1][1] == map[1][2])
	{	
		printf("winner is %c\n", map[1][0]);
		break;
	}

	if(map[2][0] != '*' && map[2][0] == map[2][1] && map[2][1] == map[2][2])
	{
		printf("winner is %c\n", map[2][0]);
		break;
	}

	if(map[0][0] != '*' && map[0][0] == map[1][0] && map[1][0] == map[2][0])
	{
		printf("winner is %c\n", map[0][0]);
		break;
	}

	if(map[0][1] != '*' && map[0][1] == map[1][1] && map[1][1] == map[2][1])
	{
		printf("winner is %c\n", map[0][1]);
		break;
	}

	if(map[0][2] != '*' && map[0][2] == map[1][2] && map[1][2] == map[2][2])
	{
		printf("winner is %c\n", map[0][2]);
		break;
	}

	if(map[0][0] != '*' && map[0][0] == map[1][1] && map[1][1] == map[2][2])
	{
		printf("winner is %c\n", map[0][0]);
		break;
	}

	if(map[0][2] != '*' && map[0][2] == map[1][1] && map[1][1] == map[2][0])
	{
		printf("winner is %c\n", map[0][0]);
		break;
	}


	//更换角色
	char temp = 'o' ^ 'x';
	player = player ^ temp;

	}

	if(i == 9)
		printf("this game ended in a draw\n");	

	return 0;
}
