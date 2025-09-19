/*
============================================================================
Name : 1b.c
Author : Deep Patel
Description : Create the following types of a files using (i) shell command (ii) system call
	      b. hard link (link system call)
Date: 7 Sept, 2025.
============================================================================
*/


#include <unistd.h>  
#include <stdio.h>    

int main() {
    if (link("hardfile.txt", "hardlink.txt") == 0) {
        printf("Hard link created...\n");
    }

    else{
	 perror("error in link....");
    }

    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1b$ gcc 1b.c -o 1b
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1b$ ./1b
Hard link created...
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1b$ ls -l
total 28
-rwxrwxr-x 1 deep deep 16040 Sep  7 14:40 1b
-rw-rw-r-- 1 deep deep   736 Sep  7 14:39 1b.c
-rw-rw-r-- 2 deep deep    49 Aug 24 12:43 hardfile.txt
-rw-rw-r-- 2 deep deep    49 Aug 24 12:43 hardlink.txt

============================================================================
*/


