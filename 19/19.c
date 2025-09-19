/*
============================================================================
Name : 19.c
Author : Deep Patel
Description : Write a program to find out time taken to execute getpid system 
              call. Use time stamp counter. 
Date: 7 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdint.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t start, end;
    pid_t pid;
    start = rdtsc();
    pid = getpid();
    end = rdtsc();
    printf("PID: %d\n", pid);
    printf("getpid() took %lu CPU cycles\n", end - start);
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/19$ gcc 19.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/19$ ./a.out
PID: 12785
getpid() took 20944 CPU cycles

============================================================================
*/
