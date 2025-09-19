/*
============================================================================
Name : 25.c
Author : Deep Patel
Description : Write a program to create three child processes. The parent 
	      should wait for a particular child (use waitpid system call). 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    pid1 = fork();
    if(pid1 == 0){
	    printf("Child 1 ProcessID = %d is running,  Parent ProcessID = %d\n", getpid(), getppid());
	    sleep(4);
	    printf("Child 1 ProcessID=%d existing!.!\n", getpid());
	    exit(2);
    }

    pid2 = fork();
    if(pid2 == 0){
            printf("Child 2 ProcessID = %d is running,  Parent ProcessID = %d\n", getpid(), getppid());
            sleep(8);
            printf("Child 2 ProcessID=%d existing...\n", getpid());
            exit(4);
    }

    pid3 = fork();
    if(pid3 == 0){
            printf("Child 3 ProcessID = %d is running,  Parent ProcessID = %d\n", getpid(), getppid());
            sleep(10);
            printf("Child 3 ProcessID=%d existing...\n", getpid());
            exit(6);
    }


    pid_t waited = waitpid(pid2, &status, 0);
    if (waited > 0 && WIFEXITED(status)) {
        printf("Parent: Child with ProcessID=%d exited with status=%d\n", waited, WEXITSTATUS(status));
    }

    while(wait(NULL) > 0);

    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/25$ gcc 25.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/25$ ./a.out
Child 1 ProcessID = 13676 is running,  Parent ProcessID = 13675
Child 2 ProcessID = 13677 is running,  Parent ProcessID = 13675
Child 3 ProcessID = 13678 is running,  Parent ProcessID = 13675
Child 1 ProcessID=13676 existing!.!
Child 2 ProcessID=13677 existing...
Parent: Child with ProcessID=13677 exited with status=4
Child 3 ProcessID=13678 existing...
============================================================================
*/
