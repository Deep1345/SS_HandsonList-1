/*
============================================================================
Name : 14.c
Author : Deep Patel
Description : Write a program to find the type of a file.
		 a. Input should be taken from command line.
		 b. program should be able to identify any type of a file. 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	struct stat s;
	if(argc != 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	if(stat(argv[1], &s) == -1){ 
		perror("stat");
		exit(1);
	}
	if(S_ISREG(s.st_mode)){
		printf("File Type: Regular\n");
	}
	else if(S_ISDIR(s.st_mode)){
		printf("File Type: Directory\n");
	}
	else if(S_ISCHR(s.st_mode)){
		printf("File Type: Character Device\n");
	}
	else if(S_ISLNK(s.st_mode)){
                printf("File Type: Symbolic Link\n");
        }
	else if(S_ISFIFO(s.st_mode)){
                printf("File Type: FIFO (pipe)\n");
        }
	else if(S_ISBLK(s.st_mode)){
                printf("File Type: Block Device\n");
        }
	else if(S_ISSOCK(s.st_mode)){
                printf("File Type: Socket\n");
        }
	else{
		printf("File Type: Unknown\n");
	}
	return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/14$ gcc 14.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/14$ ./a.out file.txt
File Type: Regular
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/14$ ./a.out 14.c
File Type: Regular
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/14$ ./a.out /etc
File Type: Directory

============================================================================
*/
