/*
============================================================================
Name : 20.c
Author : Deep Patel
Description : Find out the priority of your running program. Modify the priority 
              with nice command. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
int main() {
    int pri;
    pri = getpriority(PRIO_PROCESS, 0);
    printf("PID: %d\n", getpid());
    printf("Current nice value= %d\n", pri);
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/20$ gcc 20.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/20$ ./a.out
PID: 12908
Current nice value= 0
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/20$ nice -n 5 ./a.out
PID: 12909
Current nice value= 5

============================================================================
*/
