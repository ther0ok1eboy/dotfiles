#include <stdio.h>

typedef struct 
{
	int ID;        //4
	char name[64]; //64
	float salary;  //4 按照最大类型(int=4)的倍数对齐数据

}Staff;

int txt_operator()
{
	Staff staff = {0, "staff_demo", 0.0};
	FILE* p_file = fopen("staff_table_version_2.txt", "a");
	if(!p_file)
	{
		printf("open file error\n");
		return 0;
	}

	for(int i = 0; i < 2; i++)
	{
		printf("please input the ID, name and salary of staff  ");
		scanf("%d %s %g",&staff.ID, staff.name, &staff.salary);

		fprintf(p_file, "%d %s %g\n",staff.ID, staff.name, staff.salary);
	}

	fclose(p_file);
	p_file = NULL;

	return 0;
}

int bin_operator()
{

	Staff staff = {0, "staff_demo", 0.0};
	FILE* p_file = fopen("staff_table_version_1.bin", "ab");
	if(!p_file)
	{
		printf("open file error\n");
		return 0;
	}

	for(int i = 0; i < 2; i++)
	{
		printf("please input the ID of staff  ");
		scanf("%d",&staff.ID);
		scanf("%*[^\n]");
		scanf("%*c");

		printf("please input the name of staff  ");
		fgets(staff.name, 64, stdin);

		printf("please input the salary of staff  ");
		scanf("%f", &staff.salary);
		printf("\n");

		fwrite(&staff, sizeof(staff), 1, p_file);
	}

	fclose(p_file);
	p_file = NULL;

	return 0;

}

void main()
{
	bin_operator();
	//txt_operator();

}
