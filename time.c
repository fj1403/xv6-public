#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid;
    int child_pid, wait, run;
    pid = fork();
    if (pid < 0)
    {
        printf(1, "faild!\n");
        exit();
    }
    if (pid == 0)
    {
        printf(1, "child created with pid %d\n", getpid());
    }
    else
    {
		//delay for wait child
        for (int i = 0; i < 1000; i++) 
        {
            printf(1, "%d", i);
        }
        child_pid = waitx(&wait, &run);
        printf(1, "\n wait time : %d , RunTime : %d with childpid : %d\n", wait, run, child_pid);
    }
    exit();
} 