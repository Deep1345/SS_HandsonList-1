/*
============================================================================
Name : 18a.c
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
    int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0664);
    char record1[RECORD_SIZE] = "MT2025029 Bhautik 22\n";
    char record2[RECORD_SIZE] = "MT2025055 Jenish 21\n";
    char record3[RECORD_SIZE] = "MT2025039 Deep 19\n";
    memset(record1 + strlen(record1), 0, RECORD_SIZE - strlen(record1));
    memset(record2 + strlen(record2), 0, RECORD_SIZE - strlen(record2));
    memset(record3 + strlen(record3), 0, RECORD_SIZE - strlen(record3));
    write(fd, record1, RECORD_SIZE);
    write(fd, record2, RECORD_SIZE);
    write(fd, record3, RECORD_SIZE);
    printf("File created with 3 student records...\n");
    close(fd);
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/18$ gcc 18a.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/18$ ./a.out
File created with 3 student records...

============================================================================
*/
