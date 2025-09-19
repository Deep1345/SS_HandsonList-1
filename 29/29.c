/*
============================================================================
Name : 29.c
Author : Deep Patel
Description : Write a program to get scheduling policy and modify the scheduling 
              policy (SCHED_FIFO, SCHED_RR). 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_OTHER: printf("Current Policy: SCHED_OTHER\n"); break;
        case SCHED_FIFO:  printf("Current Policy: SCHED_FIFO\n"); break;  
        case SCHED_RR:    printf("Current Policy: SCHED_RR\n"); break;    
        default:          printf("Unknown Policy\n"); break;
    }
}
int main() {
    int policy;
    struct sched_param param;
    policy = sched_getscheduler(0);   
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }
    print_policy(policy);
    param.sched_priority = 10;   					
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) { 		
        printf("Failed to change policy: %s\n", strerror(errno));
    } else {
        printf("Policy changed to SCHED_FIFO successfully.\n");
    }
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(1);
    }
    print_policy(policy);
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/29$ gcc 29.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/29$ sudo ./a.out
[sudo] password for deep: 
Current Policy: SCHED_OTHER
Policy changed to SCHED_FIFO successfully.
Current Policy: SCHED_FIFO
============================================================================
*/
