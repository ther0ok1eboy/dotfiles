
#include <stdio.h>
#include "/home/jason/uc_study/day_16/lib/add.h"
//#include <add.h> //(通过gcc -c main.c -v 看系统指定的目录)把其放在系统制定的目录下(易污染系统文件)
//gcc -c main.c -I+the path of head_file(暂时放在系统目录下)

int main(void)
{
	printf("lib call sucessfully %d\n", add(333, 333));
	printf("lib call sucessfully again %d\n", sub(999, 333));
	return 0;
}
