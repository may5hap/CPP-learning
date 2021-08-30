#include<unistd.h>
#include<iostream>
#include<string.h>

using namespace std;

int main(){
    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        exit(1);
    }
    else if(pid==0){
        cout<< "child process---" <<endl;

        // execlp("ls","ls","-l","-h",NULL);
        // execlp -p means PATH environment
        // if execlp executes successfully, no return

        // if need to execute an self-defined program, use execl()
        // execl("./forktest","forktest",NULL); 
        execl("/bin/ls","/bin/ls","-al","-h",NULL);
        perror("execl error");
    }
    else if(pid > 0){
        cout << "parent process---" << endl;
    }

    return 0;
}