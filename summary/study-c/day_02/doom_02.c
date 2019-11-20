#include<stdio.h>

void main ()
{

char ch01 = 't';
int ch02 = 1;

// 'a' ==> 97 ==> 0110 0001
// 'A' ==> 65 ==> 0100 0001

// ~ 遇0变1,遇1变0
// | 遇1变1
// & 遇0变0
// ^ 同0异1

ch02 = ~ch02;
printf("~ 32  ch2 = %d\n",ch02);

//                                      |
ch01 = ch01 & ~32; //downer to upper  0110 0001 97  a
printf("& ~32  ch01 = %c\n",ch01); //&1101 1111 ~32 ==> 0100 0001 65 A

ch01 = ch01 | 32;  //upper to downer  0100 0001 65 A
printf("| 32  ch01 = %c\n",ch01);  //|0010 0000 32  ==> 0110 0001 97 a

ch01 = ch01 ^ 32;  //upper to downer or downer to upper
printf("^ 32  ch01 = %c\n",ch01);                       

//unsigned number >> ,left blank erea fills with 0
//  signed number >> ,left blank erea fills with 1
// >>n ==> /2^n
// <<n ==> *2^n
// << and >> both do not modify the source value in computer

// & obtian address of varible   0xabffffff 0000 *8 ==> 32bits
// all the addresses in computer are combinede with 32 binary bits

printf("HelloWorld!!\n");

}
