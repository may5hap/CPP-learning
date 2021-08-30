#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<string>
#include<fcntl.h>
#include<errno.h>

using namespace std;

void sys_err(const char* str){
    perror(str);
    exit(0);
}
int main(){
    pid_t pid;
    int fd;

    pid = fork();
    if(pid<0) sys_err("fork error");
    else if(pid == 0){
        //child process
        pid = setsid();         
        int ret = chdir("/Users/whao");
        if(ret<0) sys_err("chdir error");
        
        umask(0022);

        close(STDIN_FILENO);
        fd = open("/dev/null",O_RDWR);
        if(fd<0) sys_err("open error");

        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);

        while(1);

        return 0;
    }
    else exit(0);   //parent process exit


}