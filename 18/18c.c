/*
============================================================================
Name : 18c.c
Author : Deep Pate;
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

#define RECORD_SIZE 50

int main() {
    int fd = open("file.txt", O_RDONLY);
    int rno;
    char buf[RECORD_SIZE];

    printf("Enter record number to read (1-3): ");
    scanf("%d", &rno);
    rno--;  

    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = rno * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();
    
    if (fcntl(fd, F_SETLKW, &lock) == -1) { 
	    perror("Read lock failed"); 
	    exit(1); 
    }

    printf("Read lock acquired on record %d\n", rno+1);

    printf("inside the critical section...\n");

    lseek(fd, rno * RECORD_SIZE, SEEK_SET);
    read(fd, buf, RECORD_SIZE);
    printf("Record %d: %s\n", rno+1, buf);
     
    getchar();
    printf("Press ENTER to release lock...\n");
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
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/18$ gcc 18c.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/18$ ./a.out
Enter record number to read (1-3): 3
Read lock acquired on record 3
inside the critical section...
Record 3: MT2025039 Deep 19

Press ENTER to release lock...

Unlocked record 3

============================================================================
*/
