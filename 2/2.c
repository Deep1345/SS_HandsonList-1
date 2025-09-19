/*
============================================================================
Name : 2.c
Author : Deep Patel
Description : Write a simple program to execute in an infinite loop at the 
	      background. Go to /proc directory and identify all the process 
	      related information in the corresponding proc directory.
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {       
        printf("Running in background!!!\n");
        sleep(4);               // Sleep 4 seconds to reduce CPU usage
    }
    return 0;
}


/*
============================================================================
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/2$ gcc 2.c
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/2$ ./a.out &
[1] 8530
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/2$ Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
deep@deep-Lenovo-Legion-5-15IMH05:~/Downloads/MT2025039/2$ cd /proc/8530
deep@deep-Lenovo-Legion-5-15IMH05:/proc/8530$ ls
arch_status  clear_refs          cpuset   fdinfo             latency    mem         ns             pagemap      sched      smaps_rollup  syscall         uid_map
attr         cmdline             cwd      gid_map            limits     mountinfo   numa_maps      patch_state  schedstat  stack         task            wchan
autogroup    comm                environ  io                 loginuid   mounts      oom_adj        personality  sessionid  stat          timens_offsets
auxv         coredump_filter     exe      ksm_merging_pages  map_files  mountstats  oom_score      projid_map   setgroups  statm         timers
cgroup       cpu_resctrl_groups  fd       ksm_stat           maps       net         oom_score_adj  root         smaps      status        timerslack_ns

============================================================================
*/
