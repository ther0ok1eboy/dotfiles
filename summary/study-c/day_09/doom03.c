#include <stdio.h>

int main01()
{
//gcc -DTWO doom03.c

//#ifdef ONE
#ifndef	TWO
	printf("ONE \n");
#else
	printf("TWO \n");
#endif

	return 0;
}

int main02()
{
//gcc -DA doom03.c

#if defined(A)
	printf("A\n");
#elif !defined(A)&&!defined(B)
	printf("C\n");
#else
	printf("B\n");
#endif
	return 0;

}

int main()
{
	main02();
	return 0;
}
