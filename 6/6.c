/*
============================================================================
Name : 6.c
Author : Deep Patel
Description : Write a program to take input from STDIN and display on STDOUT. 
	      Use only read/write system calls
Date: 7 Sept, 2025.
============================================================================
*/

#include<unistd.h>
#include<stdlib.h>
int main(){
	char buff[50];
	int i;
	i = read(0, buff, sizeof(buff));  //store number of charactar in i
	if(i<0){
		write(2, "Read Error!!!\n", 14);  //2=STDERR  14 is for size of error msg  
		exit(1);
	}
	write(1, buff, i);
	return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/6$ gcc 6.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/6$ ./a.out
Hey !!
Hey !!

============================================================================
*/
