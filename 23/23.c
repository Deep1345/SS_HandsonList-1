/*
============================================================================
Name : 23.c
Author : Deep Patel
Description : Write a program to create a Zombie state of the running program. 
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
        printf("Child PID=%d is exiting immediately...\n\n", getpid());
	exit(0);  
    } 
    else {
        printf("Parent PID=%d is sleeping...\n", getpid());
	sleep(60);
    }

    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/23$ gcc 23.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/23$ ./a.out
Parent PID=13261 is sleeping...
Child PID=13262 is exiting immediately...
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/23$ ps aux | grep defunct
deep        6729  0.0  0.0      0     0 ?        Z    14:17   0:00 [sd_espeak-ng-mb] <defunct>
deep       13294  0.0  0.0  17812  2288 pts/2    S+   17:39   0:00 grep --color=auto defunct

============================================================================
*/
