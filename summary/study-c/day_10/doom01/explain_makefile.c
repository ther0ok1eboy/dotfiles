/*
a.out : add_m.o add_c.o      //a.out from add_m.o and add_c.o, not have .h file    
(tab)	gcc add_m.o add_c.o  //how to gain add_m.o and add_c.o ? use gcc (not gcc -c)   

add_m.o : add_m.c           //add.o from add_m.c 
	gcc -c add_m.c      //how to gain add_m.o ? use gcc -c add_m.c

add_c.o : add_c.c           //similar with above all
	gcc -c add_c.c
*/

//当目录下有多个makefile时
//在当前目录使用 make -f makefile01/makefile02...
