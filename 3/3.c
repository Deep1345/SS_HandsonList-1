/*
============================================================================
Name : 3.c
Author : Deep Patel
Description : Write a program to create a file and print the file descriptor 
	      value. Use creat ( ) system call
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

int main(){
	int f;
	// creat() syntax: int creat(const char *pathname, mode_t mode)
	fd = creat("file.txt", 0644);
	if(f == -1){
		perror("create");
		exit(1);
	}
	printf("File created!!!\n");
	//print normally 3, because 0,1,2 are stdin, stdout, stderr
	printf("File Descriptor Value: %d", f);
	close(f);
	return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/3$ gcc 3.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/3$ ./a.out
File created!!!
File Descriptor Value: 3
============================================================================
*/
