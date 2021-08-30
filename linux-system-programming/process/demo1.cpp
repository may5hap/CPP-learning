#include<unistd.h>
#include<iostream>
#include<string>
#include<fcntl.h>

using namespace std;

/* * to redirect the result of "ps -aux" to file "ps.out"  */

int main(){
    int fd;
    fd = open("ps.out", O_RDWR | O_TRUNC | O_CREAT, 0644);
    // open the file "ps.out"

    dup2(fd,STDOUT_FILENO);
    // redirect the result from standard output to file "file.out"

    execlp("ps","ps","-aux",NULL);
    // execute the order "ps -aux"

    return 0;
}