/*
============================================================================
Name : 5.c
Author : Deep Patel
Description : Write a program to create five new files with infinite loop. 
	      Execute the program in the background and check the file descriptor 
	      table at /proc/pid/fd.
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int f[5];
	char fdname[30];

	//creat 5 files
	for(int i=0; i<5; i++){
		sprintf(fdname, "file%d.txt", i+1); // Prints into a string (array) instead of the screen.
		f[i] = creat(fdname, 0644);
		if(f[i] == -1){
			perror("create");
			exit(1);
		}

		printf("Created %s with f=%d\n", fdname, f[i]);
	}

	while(1){
		sleep(2); // avoid wasting CPU while waiting..
	}

	return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/5$ ./a.out &
[1] 9037
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/5$ Created file1.txt with fd=3
Created file2.txt with fd=4
Created file3.txt with fd=5
Created file4.txt with fd=6
Created file5.txt with fd=7
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/5$ ls -l /proc/9037/fd
total 0
lrwx------ 1 deep deep 64 Sep  7 15:24 0 -> /dev/pts/1
lrwx------ 1 deep deep 64 Sep  7 15:24 1 -> /dev/pts/1
lrwx------ 1 deep deep 64 Sep  7 15:24 2 -> /dev/pts/1
l-wx------ 1 deep deep 64 Sep  7 15:24 3 -> /home/deep/Desktop/MT2025039/5/file1.txt
l-wx------ 1 deep deep 64 Sep  7 15:24 4 -> /home/deep/Desktop/MT2025039/5/file2.txt
l-wx------ 1 deep deep 64 Sep  7 15:24 5 -> /home/deep/Desktop/MT2025039/5/file3.txt
l-wx------ 1 deep deep 64 Sep  7 15:24 6 -> /home/deep/Desktop/MT2025039/5/file4.txt
l-wx------ 1 deep deep 64 Sep  7 15:24 7 -> /home/deep/Desktop/MT2025039/5/file5.txt

============================================================================
*/
