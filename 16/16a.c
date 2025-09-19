/*
============================================================================
Name : 16a.c
Author : Deep Patel
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
        f = open("lockFile.txt", O_WRONLY | O_CREAT, 0664);
        if(f == -1){
                perror("open");
                exit(1);
        }

        lock.l_type = F_WRLCK;     
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;         
        lock.l_len = 0;        	
	lock.l_pid = getpid();
        printf("Before entering into the critical section (write lock))!!!\n");
        fcntl(f, F_SETLKW, &lock);
        printf("Inside the critical the section with write lock!!!\n");
        printf("Enter to unlock!!!\n");
        getchar();
        printf("Unlocked...\n");
        lock.l_type = F_UNLCK;
        fcntl(f, F_SETLK, &lock);
        close(f);
        return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/16$ gcc 16a.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/16$ ./a.out 
Before entering into the critical section (write lock))!!!
Inside the critical the section with write lock!!!
Enter to unlock!!!

Unlocked...

============================================================================
*/
