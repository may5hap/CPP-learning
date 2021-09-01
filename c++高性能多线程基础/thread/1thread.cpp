#include<iostream>
#include<thread>

using namespace std;

void hello(){
    cout << "hello, this is child thread" << endl;
}

int main(){
    thread t(hello);
    t.join();
    cout << "end of main" <<endl;
    return 0;
}