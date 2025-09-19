/*
============================================================================
Name : 16b.c
Author : Bhautik Vekariya
Description : Write a program to perform mandatory locking.
                  a. Implement write lock
                  b. Implement read lock   
Date: 7 Sept, 2025.
============================================================================
*/

#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
        int f;
        struct flock lock;
        f = open("lockFile.txt", O_RDONLY, 0644);
        if(f == -1){
                perror("open");
                exit(1);
        }

        lock.l_type = F_RDLCK;    
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;         
        lock.l_len = 0;          
	lock.l_pid = getpid();

        printf("Before entering into the critical section (read lock)!!!\n");
        fcntl(f, F_SETLKW, &lock);
        printf("Inside the critical the section with read lock!!!\n");
        printf("Enter to unlock!!!\n");
        getchar();
        printf("Unlocked\n");

        lock.l_type = F_UNLCK;
        fcntl(f, F_SETLK, &lock);

        close(f);
        return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/16$ gcc 16b.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/16$ ./a.out 
Before entering into the critical section (read lock)!!!
Inside the critical the section with read lock!!!
Enter to unlock!!!

Unlocked

============================================================================
*/
