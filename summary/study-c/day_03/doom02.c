#include <stdio.h>

int main()
{
//隐式转换 小数据类型 => 大 推荐  大 => 小 会丢失数据
printf("sizeof(1 ? 1 : 0.9) %ld\n",sizeof(1 ? 1 : 0.9)); // 8

printf("sizeof(-7 + 3 > 0) %d\n", -7 + 3 > 0);
printf("sizeof(-7 + 3u > 0) %d\n", -7 + 3u > 0);

//强转可能造成数据丢失
//类型转换不会修改存储区内容，计算机会将结果放新的存储区
//scanf()可修改存储区的内容哦

// 300 ==> 4 byte ==>32 bit
// 0000 0000/0000 0000/0000 0001/0010 1100
// int ==> char char只能读到4byte最后1byte里的内容
//                              /0010 1100 ==> 44
printf("(char)300 %d\n", (char)300); //44






return 0;
}
