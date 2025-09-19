/*
============================================================================
Name : 13.c
Author : Deep Patel
Description : Write a program to wait for a STDIN for 10 seconds using select. 
              Write a proper print statement to verify whether the data is 
	      available within 10 seconds or not (check in $man 2 select). 
Date: 7 Sept, 2025.
============================================================================
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main(){
	fd_set rfd;
	struct timeval t;
	int r;

	FD_ZERO(&rfd);
	FD_SET(STDIN_FILENO, &rfd);

	t.tv_sec=10;
	t.tv_usec=0;  //milisecond
	
	printf("Type your input within 10 sec\n");

	r = select(STDIN_FILENO + 1, &rfd, NULL, NULL, &t);

	if(r==0){
		printf("Your data is not available within 10 sec...\n");
	}
	else if(r==-1){
		perror("select");
		exit(1);
	}
	else{
		if(FD_ISSET(STDIN_FILENO, &rfd)){
			printf("Your data is now available...\n");

			char buf[100];
			if(fgets(buf, sizeof(buf), stdin) != NULL){
				printf("Data is: %s", buf);
			}
		}
	}

	return 0;

}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/13$ gcc 13.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/13$ ./a.out
Type your input within 10 sec
Hey There!!!
Your data is now available...
Data is: Hey There!!!

============================================================================
*/
