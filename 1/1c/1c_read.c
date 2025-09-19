/*
============================================================================
Name : 1c_read.c
Author : Deep Patel
Description : Create the following types of a files using (i) shell command (ii) system call
	      c. FIFO (mkfifo Library Function or mknod system call)              
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int f;
    char *fifo_path = "myfifo";
    char buffer[100];

    // Create FIFO if it doesn't exist
    mkfifo(fifo_path, 0644);

    // Open FIFO for reading
    f = open(fifo_path, O_RDONLY);
    if (f < 0) {
        perror("Error in open");
        exit(1);
    }

    // Read message
    read(f, buffer, sizeof(buffer));
    printf("Reader: received message: %s\n", buffer);

    close(f);
    return 0;
}

/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1c$ gcc 1c_read.c -o read
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1c$ ./read
Reader: received message: Hi I am Deep Patel


============================================================================
*/

