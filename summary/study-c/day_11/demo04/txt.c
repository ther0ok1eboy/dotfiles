//所有文件都是采用二进制来记录数字的
//如果文件里所有数据都来自于字符
//则这种文件叫 文本文件

//C提供了两种操作文件的方式(文本方式 二进制方式)
#include <stdio.h>

void main(int args, char** argv)
{
	//文件操作的基本步骤:
	
	//1 打开文件(fopen())
	// A 参数
	//   a 要打开的文件路径
	//   b 打开文件的方式
	//     . "r"  只看不能改,从头察看,文件不存在打开失败
	//     . "r+" 比"r"多了修改功能
	//     . "w"  只能修改不能查看,从头修改,不存在则创建文件,存在则删除文件里所有内容
	//     . "w+" 比"w"多了查看功能
	//     . "a"  只能修改不能查看,在尾加新内容,不存在则创建,存在不会修改原内容
	//     . "a+" 比"a"多了查看功能
	//     . "b"  可和上面混合使用(如果采用 二进制方式 就应该包含"b")
	// B 返回值是第一地址 应该记录在文件指针里
	// C 打开有可能失败 返回值为NULL
	// D 使用完文件后必须使用fclose(FILE*) ==> 再把文件指针置空
	
	//2 操作文件(fwrite()/fread())
	// A 把内存里一组连续的存储区的内容拷贝到文件里(写文件)
	// B 把文件里一组连续存储区的内容拷贝到内存里(读文件)
	//
	//fread()可以采用  二进制方式  对文件进行读操作
	//fwrite()可以采用  二进制方式  对文件进行写操作
	//都需要四个参数
	// .内存里第一个存储区的地址
	// .内存里单个存储区的大小
	// .希望操作的存储区个数
	// .文件指针
	//其返回值表示实际操作存储区的个数
	//
	//3 关闭文件(fclose())
	
	//只能用文件指针代表打开的文件,不能用路径
	FILE* p_file =  fopen("a.bin", "wb");//会多一个a.bin file
	if(!p_file){return;}
	int arr[5] = {1, 2, 3, 4, 5};
	//写文件:
	int file_size = fwrite(arr, sizeof(int), 5, p_file);
	printf("fwrite_file_size = %d\n", file_size);
	fclose(p_file);
	p_file = NULL;

	//读文件
	p_file =  fopen("a.bin", "rb");//会多一个a.bin file
	if(!p_file){return;}
	int read_arr[5] = {0};
	file_size = fread(read_arr, sizeof(int), 5, p_file);
	printf("fread_file_size = %d\n", file_size);
	for(int i = 0; i < 5; i++)
		printf("%d ", read_arr[i]);
	fclose(p_file);
	p_file = NULL;

}
