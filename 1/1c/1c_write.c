/*
============================================================================
Name : 1c_write.c
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

    // Create FIFO if it doesn't exist
    mkfifo(fifo_path, 0666);

    // Open FIFO for writing
    f = open(fifo_path, O_WRONLY);
    if (f < 0) {
        perror("Error in open");
        exit(1);
    }

    // Take input from user
    char msg[100];
    printf("Enter a message: ");
    //stdin is a file pointer that refers to the keyboard (by default)
    fgets(msg, sizeof(msg), stdin);

    write(f, msg, sizeof(msg));

    printf("Writer: message sent!\n");

    close(f);
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/1/1c$ ./write
Enter a message: Hi I am Deep Patel
Writer: message sent!

============================================================================
*/
