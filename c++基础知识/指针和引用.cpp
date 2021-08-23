#include<iostream>

using namespace std;

int main(){
    int a = 10;
    int c = 20;
    int *p_a = &a;
    int &b=a;
    cout<<*p_a<<endl;
    cout<<b<<endl;
    //int & b = c;      //错误，引用一旦绑定之后就不能修改
    cout<<b<<endl;

    //int& c = b;       //错误，不能多级引用
    return 0;
}