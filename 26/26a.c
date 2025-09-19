/*
============================================================================
Name : 26a.c
Author : Deep Patel
Description : Write a program to execute an executable program.
	      a. use some executable program
	      b. pass some input to an executable program. (for example execute 
	      an executable of $./a.out name) 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) printf("My name is:- %s\n", argv[1]);
    else printf("please enter your name...\n");
    return 0;
}
/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/26$ gcc 26a.c -o 26a
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/26$ ./26a Deep
My name is:- Deep
============================================================================
*/

