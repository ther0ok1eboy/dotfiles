#include <stdio.h>

void main()
{
	char ch = '0';
	FILE* p_file = fopen("a.txt", "rb");

	for(int i = 0; i < 3; i++)
	{	
		printf("ftell() = %ld\n", ftell(p_file)); //0 1 2
		fread(&ch, sizeof(ch), 1, p_file);
		printf("ch = %c\n", ch);
	}
	
	rewind(p_file);
	fread(&ch, sizeof(ch), 1, p_file);
	printf("call rewind(), ch = %c\n", ch);

	/*
	fseek(p_file, 0, SEEK_END);
	fread(&ch, sizeof(ch), 1, p_file);
	printf("call fseek(), ch = %c\n", ch); // a

	fseek(p_file, 0, SEEK_SET);
	fread(&ch, sizeof(ch), 1, p_file);
	printf("call fseek(), ch = %c\n", ch); // a
	*/

	//ftell()  可获得位置指针的数值
	//rewind() 可以把位置指针的数值设为0(开头的位置)
	//fseek()  可以把位置指针设为任一位置
	//fseek()  要三个参数
	// a 文件指针	
	// b 目标位置到基准位置之间的距离(abs(距离) 为之间包含的字节个数)
	//   . 基位   目位 ==> 非负表示
	//   . 目位   基位 ==> 负数表示
	
	// c 基准位置
	//   . SEEK_SET 0 把文件头作为基准位置
	//   . SEEK_CUR 1 把当前位置～
	//   . SEEK_END 2 把文件尾～
	


	fclose(p_file);
	p_file = NULL;

}
