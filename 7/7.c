/*
============================================================================
Name : 7.c
Author : Deep Patel
Description : Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 7 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int sfd, dfd, n;
	char buf[50];

	if(argc != 3){  //if argc!=3 means one of file is missing then print this
		printf("Usage: %s <source_file> <desti file>\n", argv[0]);
		exit(1);
	}
	sfd = open(argv[1], O_RDONLY);
	if(sfd < 0){
		perror("It does not open source file");
		exit(1);
	}

	// If the file already exists and you open it with O_TRUNC, the file’s content is erased(old data is gone)
	dfd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if(dfd < 0){
		perror("It does not open destination file");
		exit(1);
	}


	while(n = read(sfd, buf, sizeof(buf))){
		if(!write(dfd, buf, n)){
			perror("There is an error writing to destination file");
			close(sfd);
			close(dfd);
			exit(1);
		}		
	}

	if(n < 0){
		perror("There has been Error reading source file");
	}

	close(sfd);
	close(dfd);

	printf("File has been copied...\n");

	return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/7$ gcc 7.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/7$ ./a.out file1.txt file2.txt
File copied!!!
============================================================================
*/
