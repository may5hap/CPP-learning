#include<unistd.h>
#include<string>
#include<sys/wait.h>

using namespace std;

void sys_error(const char* errinfo){
    perror(errinfo);    //string would be error, only const char *
    exit(0);
}

int main(){
    int pipepd[2];
    int ret;
    int pid;
    int i;

    ret = pipe(pipepd);     // create and open the pipe
    if(ret==-1){
        sys_error("pipe error!");
    }

    for(i = 0; i<2; i++){
        pid = fork();
        if(pid == 0){
            //child process
            break;
        }
        else if(pid == -1){
            sys_error("fork error!");
        }
    }

    if(i == 2){
        //parent process
        close(pipepd[0]);   //the parent process should close fd for pipe
        close(pipepd[1]);
        wait(NULL);
        wait(NULL);
    }
    else if(i == 0){
        // big brother process, for writting to pipe 
        close(pipepd[0]);   //close the read fd
        dup2(pipepd[1],STDOUT_FILENO);  //redirect the standard output to pipe's write fd
        execlp("ls","ls","-a","-l",NULL);
        sys_error("execlp ls error!");
    }
    else if(i == 1){
        // little brother process, for reading from pipe
        close(pipepd[1]);   // close the write fd
        dup2(pipepd[0],STDIN_FILENO);   //redirect the standard input to pipe's read fd
        execlp("wc","wc","-l",NULL);
        sys_error("execlp wc -l error!");
    }


}