/*
============================================================================
Name : 11.c
Author : Deep Patel
Description : Write a program to open a file, duplicate the file descriptor and 
	      append the file with both the descriptors and check whether the 
	      file is updated properly or not.
	      a. use dup
              b. use dup2
	      c. use fcntl 

Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
	int fd, dup_fd, dup2_fd, fcntl_fd;

	fd = open("file.txt", O_WRONLY|O_CREAT|O_APPEND, 0664);
	if(fd<0){
		perror("open");
		exit(1);
	}

	dup_fd = dup(fd); 
	if(dup_fd < 0){
		perror("There has been a dup error");
		exit(1);
	}
	dup2_fd = dup2(fd, 20);  
	if(dup2_fd < 0){
		perror("There has been a dup2 error");
		exit(1);
	}
	fcntl_fd = fcntl(fd, F_DUPFD, 25);  
	if(fcntl_fd < 0){
		perror("fcntl error!!!");
		exit(1);
	}
	write(fd, "writting wit fd\n", sizeof("writting wit fd\n"));
	write(dup_fd, "writting wit dup_fd\n", sizeof("writting wit dup_fd\n"));
	write(dup2_fd, "writting wit dup2_fd\n", sizeof("writting wit dup2_fd\n"));
	write(fcntl_fd, "writting wit fcntl_fd\n", sizeof("writting wit fcntl_fd\n"));
	close(fd);
	close(dup_fd);
	close(dup2_fd);
	close(fcntl_fd);

	return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/11$ gcc 11.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/11$ ./a.out
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/11$ cat file.txt
writting wit fd
writting wit dup_fd
writting wit dup2_fd
writting wit fcntl_fd

============================================================================
*/
