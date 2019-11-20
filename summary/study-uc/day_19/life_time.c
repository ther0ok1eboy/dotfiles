#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

extern int g_val;
void count(void)
{
	//int val = 1;
	static int val = 1;
	printf("val = %d\n", val++);
	printf("g_val = %d\n", g_val);
	printf("&val = %p\n", &val);

	return;

}

int g_val = 666;
const int g_c_val = 66;
const static int gcsval = 6666;
int main(void)
{
	const int c_val = 666;
	printf("c_val1 = %p\n", &c_val);
	int *p_c_val = &c_val;
	printf("c_val2 = %p\n", &c_val);


	printf("getpid = %d\n", getpid());
	printf("g_c_val = %p\n", &g_c_val);
	printf("gcsval = %p\n", &gcsval);
	//for(int i = 0; i < 5; i++)
	//	count();

	printf("&g_val = %p\n", &g_val);
	getchar();

	return 0;
}
