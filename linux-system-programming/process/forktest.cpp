#include<unistd.h>
#include<iostream>

using namespace std;

int main(){
    int a = 10;
    cout<< "father process -1-"<<endl;
    cout<< "father process -2-"<<endl;
    cout<< "father process -3-"<<endl;
    cout<< "father process -4-"<<endl;

    //create a child process
    pid_t cpid = fork();
    if(cpid < 0){
        perror("fork error");
    }
    else if(cpid==0){                          // if cpid == 0, it means the current process is the child process
        a++;
        cout << "child process" << a << endl;
        cout << "child process---" << " my process id: " << getpid() << " my father process id: " << getppid() << "  " << &a << endl;
    }
    else if(cpid > 0){                          //if cpid is bigger than 0, the current process is the father process and cpid is the child process id
        a++;
        cout << "main process" << a << endl; 
        cout << "father process---" << " my process id: " << getpid() << " my father process id: " << getppid() << " my child process:" << cpid << "  " << &a << endl;
    }
    cout << "child and father process" << endl;
    return 0;
}