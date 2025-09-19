/*
============================================================================
Name : 1a.c
Author : Deep Patel
Description : Create the following types of a files using (i) shell command (ii) system call
	      a. soft link (symlink system call)
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    // Create a soft link: systemlink.txt -> softfile.txt
    if (symlink("softfile.txt", "systemlink.txt") == 0) {
        printf("Soft link created successfully.\n");
    } 
    
    else {
        perror("Error in symlink...");
    }
    
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/1/1a$ gcc 1a.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/1/1a$ ./a.out
Soft link created successfully.
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/1/1a$ ls -l
total 40
-rwxrwxr-x 1 deep deep 16048 Sep  6 15:54 1a
-rw-rw-r-- 1 deep deep   823 Sep  7 14:33 1a.c
-rwxrwxr-x 1 deep deep 16048 Sep  7 14:33 a.out
-rw-rw-r-- 1 deep deep    38 Aug 24 12:10 softfile.txt
lrwxrwxrwx 1 deep deep    12 Sep  7 14:33 systemlink.txt -> softfile.txt

============================================================================
*/

