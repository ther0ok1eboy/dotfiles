#include <stdio.h>

int main(int args, char* argv[])
{

	int marks = -1;
	int marks_sum = 0;
	FILE* p_file = fopen("marks_results.txt", "r");
	if(!p_file){return 0;};

	while(1)
	{
		
		fscanf(p_file, "%d", &marks);
		if(marks == 0)
			break;
		marks_sum += marks;
	}
	fclose(p_file);
	p_file = NULL;

	printf("sum of marks is %d\n", marks_sum);
	return 0;
}
