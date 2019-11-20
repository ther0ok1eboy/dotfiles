#ifndef __BASH_H_
#define __BASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <open_file.h>
#include <string.h>

//将命令分成两段放两个数组
void turn(char *arg[] ,char *buf, int len);
//cat 命令:
void cat(char *a, char *b);
//ls 命令
void ls(char *a, char *b);
//ps 命令
void ps(char *a, char *b);
//which 命令
void which(char *a, char *b);
//env 命令
void env(char *a, char *b);

#endif //__BASH_H_


