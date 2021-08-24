#include<iostream>
using namespace std;

void f1(int a){
    cout<<"值传递，形参的地址："<<&a<<endl;
}

void f2(int * a){
    cout<<"指针传递，形参的地址："<<a<<endl;
}

void f3(int& a){
    cout<<"引用传递，形参的地址："<<&a<<endl;
}

int main(){
    int n = 10;
    cout<<"实参的地址："<<&n<<endl;
    f1(n);
    f2(&n);
    f3(n);
    return 0;
}