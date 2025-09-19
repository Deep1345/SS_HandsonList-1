/*
============================================================================
Name : 24.c
Author : Deep Patel
Description : Write a program to create an orphan process. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        printf("I am the orphan child!!!\n");
        printf("I am child having ProcessID = %d\n", getpid());
        printf("My parent's ProcessID = %d\n", getppid());

	sleep(15);
	printf("New parent's PID = %d\n", getppid());
    }
   
    else {
        printf("I am parent having ProcessID = %d\n", getpid());
	printf("My child's ProcessID = %d\n", pid);
        printf("Parent exiting now!!!\n\n");
        exit(0);  
    }

    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/24$ gcc 24.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/24$ ./a.out
I am parent having ProcessID = 13488
My child's ProcessID = 13489
Parent exiting now!!!

I am the orphan child!!!
I am child having ProcessID = 13489
My parent's ProcessID = 13488
New parent's PID = 1889
============================================================================
*/
