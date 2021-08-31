#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<string>

using namespace std;

void * tfn(void * args){
    cout << "子线程：" << "进程号：" << getpid() << "  线程号：" << pthread_self() <<endl; 
    return nullptr;
}

void sys_err(const char* info){
    perror(info);
    exit(0);
}

int main(){
    pthread_t tid;

    int ret = pthread_create(&tid, nullptr, tfn, nullptr);
    if(ret != 0){
        sys_err("pthread_create error");
    }

    cout << "主线程：" << "进程号：" << getpid()<< "  线程号：" << pthread_self()<<endl;

    return 0;

}