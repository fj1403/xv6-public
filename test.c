#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

struct proc_info {
    int pid;
    int memsize;            
};

int main(void){

    int first_child=fork();      // make child and parent
    if(first_child==0)
    {
        char* t = malloc(7000000* sizeof(char*));
        for(int i=0;i<7000000;i++)
        {   // big loop to dont finish process soon
            t[i]='t';    // for compile error
        }
        while(0<1){
        }
    }
    else if(first_child>0) {
        int second_child =fork();
        if(second_child ==0){
            char* a=malloc(1300000* sizeof(char(*))); //make defferent size for test syscall
            for(int i=0;i<1300000;i++)
            {
                a[i]='a';
            }
            while(0<1){
            }
        }
        else if(second_child >0) {           // parent
            sleep(20);
            struct proc_info s [NPROC];     // NPROC => number of all processes in "param.h"
            new_sys(s); //for start runing
            for(int i=0;i<NPROC;i++){
                if(s[i].pid==0)
                    break;
                printf(1,"%d\t %d\n",s[i].pid, s[i].memsize);

            }
        }
    }

    exit();
}