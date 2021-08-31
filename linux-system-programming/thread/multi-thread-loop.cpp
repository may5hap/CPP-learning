#include<iostream>
#include<string>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void sys_err(const char* info){
    perror(info);
    exit(0);
}

void * tfn(void * args){
    //int i = (int)args;
    int * i = static_cast<int*>(args); 
    //cout << "I'm " << i << "th thread." << " pid = " << getpid() << " tid = " << pthread_self()<<endl; 
    if(*i == 2) {
        pthread_exit(nullptr);
    }
    cout << "I'm " << *i << "th thread." << " pid = " << getpid() << " tid = " << pthread_self()<<endl;
}

int main(){
    pthread_t tid;
    for(int i = 0; i<5; i++){
        int ret = pthread_create(&tid, nullptr, tfn, &i);
        sleep(i+1);
        // int ret = pthread_create(&tid, nullptr, tfn, (void *)i);
        if(ret!=0){
            sys_err("pthread_create error");
        }
    }
    cout << "I'm main." << " pid = " << getpid() << " tid = " << pthread_self()<<endl;
    //sleep(5);
    pthread_exit(nullptr);
    //return 0;

}