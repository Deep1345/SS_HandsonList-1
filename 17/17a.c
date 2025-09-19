/*
============================================================================
Name : 17a.c
Author : Deep Patel
Description : Write a program to simulate online ticket reservation. Implement 
              write lock. Write a program to open a file, store a ticket number 
	      and exit. Write a separate program, to open the file, implement 
	      write lock, read the ticket number, increment the number and print 
	      the new ticket number then close the file.
Date: 7th sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int f, i, ticket;
    struct flock lock;
    char buff[100];
    f = open("ticket.txt", O_RDWR);
    if (f == -1) {
        perror("open");
        exit(1);
    }
    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;           
    if (fcntl(f, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        close(f);
        exit(1);
    }
    printf("Inside the critical section ...\n");
    lseek(f, 0, SEEK_SET);
    i = read(f, buff, sizeof(buff) - 1);
    if (i <= 0) {
        perror("read");
        close(f);
        exit(1);
    }
    buff[i] = '\0';
    ticket = atoi(buff); 
    ticket++;               
    lseek(f, 0, SEEK_SET);
    dprintf(f, "%d\n", ticket);           
    ftruncate(f, lseek(f, 0, SEEK_CUR)); 
    printf("New ticket Booked: %d\n", ticket);
    printf("Enter to unlock!!!\n");
    getchar();
    printf("Unlocked\n");
    lock.l_type = F_UNLCK;
    if (fcntl(f, F_SETLK, &lock) == -1) {
        perror("fcntl");
    }
    close(f);
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/17$ gcc 17a.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/17$ ./a.out
Inside the critical section ...
New ticket Booked: 7
Enter to unlock!!!

Unlocked
============================================================================
*/

