/*
============================================================================
Name : 8.c
Author : Deep Patel
Description : Write a program to open a file in read only mode, read line by 
              line and display each line as it is read. Close the file when 
	      end of file is reached. 
Date: 7 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	FILE *ptr;
	char buff[100];
	if(argc!=2){
		printf("Usage: %s <filename>", argv[0]);
	}
	ptr = fopen(argv[1], "r");
	if(ptr == NULL){
		perror("Error in opening file");
		exit(1);
	}
	while(fgets(buff, sizeof(buff), ptr) != NULL){
		printf("%s", buff);
	}

	fclose(ptr);

	return 0;
}
/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/8$ gcc 8.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/8$ ./a.out file.txt
Hey!!!
How you doing??
============================================================================
*/
