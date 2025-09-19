/*
============================================================================
Name :22.c
Author : Deep Patel
Description : Write a program, open a file, call fork, and then write to the 
	      file by both the child as well as the parent processes. Check 
	      output of the file. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int f;
    pid_t p;

    f = open("file.txt", O_WRONLY | O_CREAT, 0666);
    if (f < 0) {
        perror("open failed");
        exit(1);
    }
    p = fork();

    if (p < 0) {
        perror("fork failed");
        exit(1);
    }

    if (p == 0) {
       	write(f, "Child process is writing to file!!!\n", sizeof("Child process is writing to file!!!"));
	printf("Writing is done by child process!!!\n");
    } 

    else {
	write(f, "Parent process is writing to file!!!\n", sizeof("Parent process is writing to file!!!"));
	printf("Writing is done by parent process!!!\n");	
    }

    close(f);
 }
/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/22$ gcc 22.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/22$ ./a.out
Writing is done by parent process!!!
Writing is done by child process!!!
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/22$ cat file.txt
Parent process is writing to file!!!
Child process is writing to file!!!

============================================================================
*/
