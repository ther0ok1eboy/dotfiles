/*test.h
 *
 *#ifndef __TEST_H__
 *#define __TEST_H__
 *
 * extern int num; //方便很多个包含test.h的.c file 使用
 *void test();
 *
 * #endif //
 *
 *********************************************************
 *
 *test_c.c
 *
 *#include "test.h"
 *
 *int num = 0; //全局变量
 *void test()
 *{
 *	return;
 *}
 *********************************************************
 */

#include <stdio.h>
//test_c.c //里面声明了一个全局变量 num

int main()
{
	extern int num; //这里不会分配内存,一般写在.h file
	
	//不可以跨文件使用静态全局变量
	return 0;
}
