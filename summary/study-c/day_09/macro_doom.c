#include <stdio.h>

#define TTT(c) ((c)^32)   // all can
#define DTU(c) ((c)& ~32) //downer to upper
#define UTD(c) ((c)|32)   //upper to downer

int main()
{
	char ch = 'd';

	printf("%c\n", UTD(DTU(ch)));
	printf("%c\n", DTU(ch));
	printf("%c\n", TTT(ch));
	return 0;
}
