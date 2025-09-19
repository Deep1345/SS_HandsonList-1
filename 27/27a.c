/*
============================================================================
Name : 27a.c
Author : Deep Patel
Description : Write a program to execute ls -Rl by the following system calls
		  a. execl
		  b. execlp
		  c. execle
		  d. execv
		  e. execvp 
Date: 7 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);

    perror("execl failed");
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ gcc 27a.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ ./a.out
Using execl:
.:
total 36
-rw-rw-rw- 1 deep deep  1251 Sep  7 10:29 27a.c
-rw-rw-rw- 1 deep deep  1375 Sep  7 10:29 27b.c
-rw-rw-rw- 1 deep deep  1321 Sep  7 10:29 27c.c
-rw-rw-rw- 1 deep deep  1344 Sep  7 11:14 27d.c
-rw-rw-rw- 1 deep deep  1343 Sep  7 11:14 27e.c
-rwxrwxr-x 1 deep deep 16040 Sep  7 18:06 a.out

============================================================================
*/

