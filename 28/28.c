/*
============================================================================
Name : 28.c
Author : Deep Patel
Description : Write a program to get maximum and minimum real time priority. 
Date: 7 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
int main() {
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_rr = sched_get_priority_max(SCHED_RR);
    int min_rr = sched_get_priority_min(SCHED_RR);
    printf("For policy SCHED_FIFO!!!\n");
    printf("Maximum Priority:  %d\n", max_fifo);
    printf("Minimum Priority:  %d\n\n", min_fifo);
    printf("For policy Round Robin!!!\n");
    printf("Maximum Priority: %d\n", max_rr);
    printf("Minimum Priority:  %d\n\n", min_rr);
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/28$ gcc 28.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/28$ ./a.out
For policy SCHED_FIFO...
Maximum Priority = 99
Minimum Priority = 1

For policy Round Robin...
Maximum Priority = 99
Minimum Priority = 1


============================================================================
*/
