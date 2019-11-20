#include <stdio.h>

int main()
{

//method one
int a = 0;
int b = 0;
int temp = 0;
printf("please input two numbers\n");
scanf("%d %d",&a,&b);
/*
temp = a;
a = b;
b = temp;
*/

//method two

/*
temp = a ^ b;
a = a ^ temp; //b   
b = b ^ temp; //a 
*/

//method three

a ^= b;      
b ^= a;       
a ^= b;
printf("a = %d b = %d",a,b);

return 0;
}
