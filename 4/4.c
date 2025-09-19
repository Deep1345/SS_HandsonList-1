/*
============================================================================
Name : 4.c
Author : Deep Patel
Description : Write a program to open an existing file with read write mode. 
	      Try O_EXCL flag also.
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>   
#include <unistd.h>  
#include <stdlib.h>  

int main() {
    int f;

    f = open("file.txt", O_RDWR);
    if (f == -1) {
        perror("error in open");
        exit(1);
    }

    printf("File opened successfully!!!\n");
    close(f);

    // Try opening with O_CREAT | O_EXCL.
    // O_EXCL → fail if the file already exists. 
    // return fd=-1 bcz file already exist.
    f = open("file.txt", O_RDWR | O_CREAT | O_EXCL, 0666);
    if (f == -1) {
        perror("open with O_EXCL...");
    } else {
        printf("File created...");
        close(f);
    }

    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/4$ gcc 4.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/4$ ./a.out
File opened successfully!!!
open with O_EXCL: File exists

============================================================================
*/

