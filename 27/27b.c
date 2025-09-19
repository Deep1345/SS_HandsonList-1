/*
============================================================================
Name : 27b.c
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
    char *envp[] = { "PATH=/bin", NULL };
    printf("Using execle:\n");
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp);
    perror("execle failed");
    return 1;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ gcc 27b.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/27$ ./a.out
Using execle:
.:
total 36
-rw-rw-rw- 1 deep deep  1148 Sep  7 18:08 27a.c
-rw-rw-rw- 1 deep deep  1375 Sep  7 10:29 27b.c
-rw-rw-rw- 1 deep deep  1321 Sep  7 10:29 27c.c
-rw-rw-rw- 1 deep deep  1344 Sep  7 11:14 27d.c
-rw-rw-rw- 1 deep deep  1343 Sep  7 11:14 27e.c
-rwxrwxr-x 1 deep deep 16096 Sep  7 18:09 a.out

============================================================================
*/
