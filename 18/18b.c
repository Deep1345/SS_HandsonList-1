/*
============================================================================
Name : 18b.c
Author : Deep Patel
Description : Write a program to perform Record locking.
                  a. Implement write lock
                  b. Implement read lock
                  Create three records in a file. Whenever you access a particular 
		  record, first lock it then modify/access to avoid race condition.
Date: 7th sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORD_SIZE 50

int main() {
    int fd = open("file.txt", O_RDWR);
    int rno;
    char buf[RECORD_SIZE];

    printf("Enter record number to write(in between 1-3) : ");
    scanf("%d", &rno);
    rno--;

   
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rno * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1) { 
	    perror("Write lock failed"); 
	    exit(1); 
    }

    printf("Write lock acquired on record %d\n", rno+1);

    printf("inside the critical section!!!\n");
    
    printf("Enter new data== ");
    getchar(); 
    fgets(buf, RECORD_SIZE, stdin);

    lseek(fd, rno * RECORD_SIZE, SEEK_SET);
    write(fd, buf, strlen(buf));

    getchar();
    printf("Press ENTER to release lock!!!\n");
    getchar();  

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) { 
	    perror("Unlock failed"); 
	    exit(1); 
    }
    printf("Unlocked record %d\n", rno+1);

    close(fd);
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/18$ ./a.out
Enter record number to write(in between 1-3) : 2
Write lock acquired on record 2
inside the critical section!!!
Enter new data== Deep 

Press ENTER to release lock!!!

Unlocked record 2

============================================================================
*/
