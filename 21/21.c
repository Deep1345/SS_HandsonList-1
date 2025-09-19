/*
============================================================================
Name : 21.c
Author : Deep Patel
Description : Write a program, call fork and print the parent and child process id. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();  

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    else if (pid == 0) {
        printf("I am the child process. Child ProcessID = %d, Parent ProcessID = %d\n", getpid(), getppid());
    }

    else {
        printf("I am the parent process.  Parent ProcessID = %d, Child ProcessID = %d\n", getpid(), pid);
    }

    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/21$ gcc 21.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/21$ ./a.out
I am the parent process.  Parent ProcessID = 13003, Child ProcessID = 13004
I am the child process. Child ProcessID = 13004, Parent ProcessID = 13003

============================================================================
*/
