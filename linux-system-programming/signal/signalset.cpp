#include<unistd.h>
#include<string>
#include<signal.h>
#include<iostream>

using namespace std;

void sys_error(const char* errinfo){
    perror(errinfo);    //string would be error, only const char *
    exit(0);
}

void printpendingset(sigset_t * pendingset){
    for(int i = 0; i<32; i++){
        if(sigismember(pendingset, i)){
            cout<<"1";
        }
        else cout<<"0";
    }
    cout<< endl;
}

int main(){
    sigset_t st, oldmask, pdmask;

    sigemptyset(&st);
    sigaddset(&st, SIGINT);
    sigaddset(&st, SIGQUIT);
    sigaddset(&st, SIGKILL);        // can not block kill and stop sig
    sigaddset(&st, SIGSTOP);

    int ret = sigprocmask(SIG_BLOCK, &st, &oldmask);
    if(ret == -1){
        sys_error("sigprocmask error");
    }

    while(1){
        ret = sigpending(&pdmask);
        if(ret == -1){
            sys_error("sigpending error");
        }

        printpendingset(&pdmask);
        sleep(1);
    }


    return 0;
}