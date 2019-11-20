#include <stdio.h>

int main01()
{
	//结构体的声明不分配内存,可声明在任何地方
	struct person
	{
		char name[31]; //31/4*4 = 28 bits
		char sex;      //4 bits
		int age;       //4 bits
		
	
	};
	//视频312 pm
	//数据对齐，每4bits一组.数据补齐
	//结构体子存储区之间可能存在空隙
	//声明结构体的时候尽量把占地小的变量先声明
	printf("sizeof(person) = %ld\n", sizeof(struct person));//36
	

	/*当struct person
	{
		char sex;      //4 bits
		int age;       //4 bits
	}时 sizeof(person) = 8
	
	而struct person
	{
		char sex;      //1 bit
		      
	}时 sizeof(person) = 1想想为啥？？？
	而struct person
	{
		char sex;      //4 bits
		char sex;      //4 bits
		int num;       //4 bits
		      
	}时 sizeof(person) = 12想想为啥？？？
	*/	
	
	//定义变量的时候为变量分配内存
	/*一种初始化方法
	struct person sorria;
	sorria.name = "xufeng";
	sorria.sex = 'M';
	sorria.age = 19;
	*/
	
	/*
	//和数组初始化遵循一样的规则
	struct person sorria = {"xufeng", 'M', 19};
	printf("name = %s\n", sorria.name);
	//printf("please input your age\n");
	//scanf("%d", &sorria.age);
	//printf("age = %d\n", sorria.age);

	struct person jason = sorria; //同类型可初始化
	printf("name = %s\n", jason.name);
	
	struct person* p_person = NULL;
	p_person = &jason;
	printf("name = %s\n", p_person -> name);
	*/
	return 0;
}

/******************下面是案例*******************/

typedef struct  Coor
{
	int x;
	int y;
	
}coor;

typedef struct Rectangle
{
	coor up_left_rctgcoor;
	coor down_right_rctgcoor;
	
}rectangle;

void centercoor_print(const rectangle* r)
{
	int center_x = (r->down_right_rctgcoor.x + r->up_left_rctgcoor.x) / 2;
	
	int center_y = (r->down_right_rctgcoor.y + r->up_left_rctgcoor.y) / 2;
	printf("center coor: (%d,%d)\n", center_x, center_y);

}

rectangle* read(void)
{
	static rectangle rctg = {0, 0, 0, 0};
	printf("please input the up left coor\n");
	scanf("%d %d", &(rctg.up_left_rctgcoor.x), &(rctg.up_left_rctgcoor.y));
	printf("please input the down right coor\n");
	scanf("%d %d", &(rctg.down_right_rctgcoor.x), &(rctg.down_right_rctgcoor.y));
	return &rctg;
}

int calc_s(const rectangle* rctg)
{
	int row_len = rctg->down_right_rctgcoor.x - rctg->up_left_rctgcoor.x;
	int col_len = rctg->down_right_rctgcoor.y - rctg->up_left_rctgcoor.y;

	return row_len * col_len >= 0 ? row_len * col_len : -(row_len * col_len);
}

int Calc_Rectangle()
{

	rectangle* rctg = read();
		
	centercoor_print(rctg);

	return calc_s(rctg);	
}


int main()
{
	//printf("S = %d\n", Calc_Rectangle());
	main01();
	return 0;

}
