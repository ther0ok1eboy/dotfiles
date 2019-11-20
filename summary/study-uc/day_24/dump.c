#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int g_val;
void hold(int signum)
{
	int l_val;
	l_val = g_val;
	l_val++;
	usleep(50000);
	printf("%d\n", l_val);
	g_val = l_val;

	return;
}
int main(void)
{
	signal(2, hold);
	while(1)
		hold(666);	
	return 0;
}
