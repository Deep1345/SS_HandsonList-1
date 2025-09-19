/*
============================================================================
Name : 30.c
Author : Deep Patel
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include <syslog.h>
#define LOGGING "Start Logging my task = %d\n"
int main()
{
    pid_t pid;
    int x_fd;
    pid = fork();
    if (pid > 0)
        exit(EXIT_SUCCESS);
    if (setsid() < 0)
        exit(EXIT_FAILURE);
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    pid = fork();
    if (pid > 0)
    {
        printf("Daemon Process ID== %d\n", pid);
        exit(EXIT_SUCCESS);
    }
    umask(077);
    chdir("/");
    for (x_fd = sysconf(_SC_OPEN_MAX); x_fd >= 0; x_fd--)
        close(x_fd);
    int count = 0;
    openlog("Logs", LOG_PID, LOG_USER);
    while (1)
    {
        sleep(2);
        syslog(LOG_INFO, LOGGING, count++);
    }
    closelog();
    return 0;
}

/*
==========================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/30$ gcc 30.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Desktop/MT2025039/30$ ./a.out
Daemon Process ID== 11747

==========================================================================
*/
