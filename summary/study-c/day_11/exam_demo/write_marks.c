#include <stdio.h>

int main(int args, char* argv[])
{

	int marks_arr[40] = {0};
	int right_marks = 0;
	FILE* p_file = fopen("marks_results.txt", "w");
	if(!p_file)
	{
		printf("open file error\n");
		return 0;
	};

	for(int i = 0; i < 5; i++)
	{
		printf("please input exam marks");
		scanf("%d", &right_marks);
		if(right_marks >= 0 && right_marks <= 100)
			marks_arr[i] = right_marks;
		else
			marks_arr[i] = 0;

		fprintf(p_file, "%d ", marks_arr[i]);
	}


	fclose(p_file);
	p_file = NULL;

	return 0;
}
