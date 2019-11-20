#include <stdio.h>

typedef struct
{
	int ID;
	char name[64];
	float salary;
}Staff;

int bin_operator()
{

	Staff staff = {0, "staff_demo", 0.0};	
	FILE* p_file = fopen("staff_table_version_1.bin", "rb");
	if(!p_file)
	{
		printf("open file error\n");
		return 0;
	}
	
	int tag = 0;
	while(1)
	{
		//sizeof(staff):文件指针向后移动的字节,方便下次读取
		tag = fread(&staff, sizeof(staff), 1, p_file);
		if(tag)
			printf("%d %g %s", staff.ID, staff.salary, staff.name);
		else
			break;
	}
	fclose(p_file);
	p_file = NULL;
	
	/*
	//能读取其中的一部分时,需要灵活的使用fseek(),下面这部分画图比较好理解	
	FILE* p_file = fopen("staff_table_version_1.bin", "rb");
	char name[64] = {0};
	int tag = 0;

	fseek(p_file, 4, SEEK_SET);
	while(1)
	{
		tag = fread(name, sizeof(name), 1, p_file);
		if(tag)
		{
			printf("%s", name);
			fseek(p_file, 8, SEEK_CUR);
		}
		else
			break;
	}
	fclose(p_file);
	p_file = NULL;
	*/	

	return 0;
}

int txt_operator()
{

	Staff staff = {0, "staff_demo", 0.0};
	FILE* p_file = fopen("staff_table_version_2.txt", "r");
	if(!p_file)
	{
		printf("open file error\n");
		return 0;
	}
	
	int tag = 0;
	while(1)
	{
		tag = fscanf(p_file, "%d %s %g", &staff.ID, staff.name, &staff.salary);
		if(tag == 3)
			printf("%d %s %g\n", staff.ID, staff.name, staff.salary);
		else
			break;
	}

	fclose(p_file);
	p_file = NULL;

	return 0;
}

void main()
{
	//bin_operator();
	txt_operator();
}
