

///   GETTING RUNNIG CPU INFO 

/* #include<bits/stdc++.h>
using namespace std;


struct pstat
{
  int  pid;       //process id
  char tcomm[256];//filename of the executable
  char state[2];  //state (R is running, S is sleeping, D is sleeping in an
                  //uninterruptible wait, Z is zombie, T is traced or stopped)
  int ppid;//          process id of the parent process
  int pgrp;//          pgrp of the process
  int sid;//           session id
  int tty_nr;//        tty the process uses
  int tty_pgrp;//      pgrp of the tty
  int flags;//         task flags
  int min_flt;//       number of minor faults
  int cmin_flt;//      number of minor faults with child's
  int maj_flt;//       number of major faults
  int cmaj_flt;//      number of major faults with child's
  int utime;//         user mode jiffies
  int stime;//         kernel mode jiffies
  int cutime;//        user mode jiffies with child's
  int cstime;//        kernel mode jiffies with child's
  int priority;//      priority level
  int nice;//          nice level
  int num_threads;//   number of threads
  int it_real_value;//  (obsolete, always 0)
  int start_time;//    time the process started after system boot
  int vsize;//         virtual memory size
  int rss;//           resident set memory size
  int rsslim;//        current limit in bytes on the rss
  int start_code;//    address above which program text can run
  int end_code;//      address below which program text can run
  int start_stack;//   address of the start of the stack
  int esp;//           current value of ESP
  int eip;//           current value of EIP
  int pending;//       bitmap of pending signals
  int blocked;//       bitmap of blocked signals
  int sigign;//        bitmap of ignored signals
  int sigcatch;//      bitmap of catched signals
  int wchan;//         address where process went to sleep
  int i0;//             (place holder)
  int i1;//             (place holder)
  int exit_signal;//   signal to send to parent thread on exit
  int task_cpu;//      which CPU the task is scheduled on
  int rt_priority;//   realtime priority
  int policy;//        scheduling policy (man sched_setscheduler)
  int blkio_ticks;//   time spent waiting for block IO
  int gtime;//         guest time of the task in jiffies
  int cgtime;//        guest time of the task children in jiffies
} p ;

int main()
{
    char name[256];
    char state[8];
    FILE* f = fopen("/proc/self/stat", "r");

    fscanf(f,  "%d%s%s%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
           &p.pid, &p.tcomm, &p.state, &p.ppid, &p.pgrp, &p.sid, &p.tty_nr, &p.tty_pgrp, &p.flags,
           &p.min_flt, &p.cmin_flt, &p.maj_flt, &p.cmaj_flt, &p.utime, &p.stime,  &p.cutime, &p.cstime,
           &p.priority, &p.nice, &p.num_threads, &p.it_real_value, &p.start_time,  &p.vsize, &p.rss,
           &p.rsslim, &p.start_code, &p.end_code, &p.start_stack, &p.esp, &p.eip,  &p.pending, &p.blocked,
           &p.sigign, &p.sigcatch, &p.wchan, &p.i0, &p.i1, &p.exit_signal,  &p.task_cpu, &p.rt_priority, &p.policy,
           &p.blkio_ticks, &p.gtime, &p.cgtime);

     printf("CPU %d\n", p.task_cpu);
     cout<<sched_getcpu()<<endl;
 return 0;  
 }*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
    cpu_set_t set;
    CPU_ZERO(&set);        // clear cpu mask
    CPU_SET(3, &set);      // set cpu 0
    sched_setaffinity(0, sizeof(cpu_set_t), &set);  // 0 is the calling process

    printf("Hello world \n");

    cout<<sched_getcpu()<<endl;

    return 0;
}