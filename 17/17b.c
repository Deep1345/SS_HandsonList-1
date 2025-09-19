/*
============================================================================
Name : 17b.c
Author : Bhautik Vekariya
Description : Write a program to simulate online ticket reservation. Implement 
              write lock. Write a program to open a file, store a ticket number 
              and exit. Write a separate program, to open the file, implement 
              write lock, read the ticket number, increment the number and print 
              the new ticket number then close the file.  
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int fd;
    int ticket = 5;
    fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    dprintf(fd, "%d\n", ticket);
    close(fd);
    printf("Ticket file associated with number %d\n", ticket);
    return 0;
}
/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/17$ gcc 17b.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/17$ ./a.out
Ticket file initialized with number 5

============================================================================
*/
