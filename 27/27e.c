/*
============================================================================
Name : 27e.c
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
    char *argv[] = { "ls", "-Rl", NULL };

    printf("Using execvp:\n");
    execvp("ls", argv);

    perror("execvp failed");
    return 1;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ gcc 27e.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ ./a.out
Using execvp:
.:
total 36
-rw-rw-rw- 1 deep deep  1148 Sep  7 18:10 27a.c
-rw-rw-rw- 1 deep deep  1270 Sep  7 18:12 27b.c
-rw-rw-rw- 1 deep deep  1213 Sep  7 18:14 27c.c
-rw-rw-rw- 1 deep deep  1237 Sep  7 18:15 27d.c
-rw-rw-rw- 1 deep deep  1343 Sep  7 11:14 27e.c
-rwxrwxr-x 1 deep deep 16096 Sep  7 18:16 a.out

============================================================================
*/
