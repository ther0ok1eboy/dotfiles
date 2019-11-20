#include <stdio.h>
#include <string.h>

//'\0'作为字符串的结尾其ASCII码就是0
//程序中内容一样的字符串在内存中是同一个
//只有包含'\0'的字符串才能当作字符串使用
//字符数组里的字符串可以修改

int main()
{
	printf("&abc =       %p\n", "abc");
	printf("abc =        %c\n", *"abc"); // a
	printf("abc + 1 =    %c\n", *"abc" + 1); // b
	printf("*(abc + 3) = %d\n", *("abc" + 3));// 0

	//*"abc" = 'z'; error 不能改,其存储区是系统分配的
	char str[5] = "abc";
	printf("sizeod(str) = %ld\n", sizeof(str)); // 5
	printf("str = %s\n", str);	
	
	//strlen():
	//char str[]="abc" 这里strlen(str)=3,所以,strcat()肯定会越界
	printf("strlen(str) = %ld\n", strlen(str));
	
	//strcat():
	//第一个参数必须是字符串数组 ？？？？	
	//合并后的字符串超过了数组的范围就会修改不属于数组的存储区,造成严重错误
	//printf("strcat() = %s\n", strcat(str, "cde"));
	//printf("strcat() = %s\n", str);
	
	//可 避免 避免
	printf("strncat() = %s\n", strncat(str, "defghi", 2));

	//strcmp():
	int bol = strcmp("acb", "acbd");
	//if(bol == 1) acb > acbd
	//bol == -1 acb < acbd
	//bol == 0 acb = acbd
		
	printf("strcmp(abc, aba) = %d\n", strcmp("abc", "aba"));
	printf("strncmp(abc, abaefg) = %d\n", strncmp("abc", "abaefg", 2));
	
	//strcpy():
	char cpyarray[32] = "abcdefghijk";
	printf("strcpy(cpyarry, hello) = %s\n", strcpy(cpyarray, "hello"));
       	// ==> cpyarray[32] = "hello\0fghijk" printf ==> hello
	//和strcat一样的越界缺点
	
	//strncpy()可能不复制'\0'
	printf("stnrcpy(cpyarry, Hello, 1) = %s\n", strncpy(cpyarray, "Hello", 1));
       	// ==> cpyarray[32] = "Hellofghijk" printf ==> Hellofghijk
	
	//memset():
	memset(str, 'x', strlen(str));
	printf("%s\n", str);

	//strstr():
	//strstr()在一个字符串中查找另一个字符串的位置,找不到返回NULL
	//返回找到字符的地址,%s可将其后面的字符串也打印出来
	printf("strstr(abcde, b) = %s\n",strstr("abcde", "b")); //bcde
	

	return 0;
}
