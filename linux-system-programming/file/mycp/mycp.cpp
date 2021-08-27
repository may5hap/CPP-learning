/**  to implement my_copy function that can copy the content of a file to another file*/

#include<unistd.h>
#include<string>
#include<fcntl.h>

int main(int argc, char* argv[]){
    char buf[1024];

    int fd1, fd2;   //for two opend files
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0664);

    int n = read(fd1, buf, 1024);      //the num of btyes read
    while(n != 0){
        write(fd2, buf, n);
        n = read(fd1, buf, 1024);
    }

    close(fd1);
    close(fd2);

    return 0;
}