#include<iostream>

using namespace std;

int func1(int a){
    return a;
}

double func2(int a){
    return 0.5*a;
}

double func3(int a){
    return 0.05*a;
}

void func4(int a, double (*p)(int)){
    cout<<(*p)(a)<<endl;
}

const int* func5(int a[],int n){
    return a;
}

const int* f1(int a[],int n){
    return a;
}

const int* f2(int a[], int n){
    return a+1;
}

const int* f3(int a[], int n){
    return a+2;
}

int main(){
    // int (*p1)(int);
    // p1=func1;
    // cout<<p1<<endl;
    // cout<<(*p1)(1)<<endl;
    // int val = 10;
    // func4(val,func2);
    // func4(val,func3);

    // const int* (*p)(int [],int);
    // p=func5;
    // int a[3] = {1,2,3};
    // cout<<(*p)(a,3)<<" : "<<*((*p)(a,3))<<endl; //理解：p是指向func5的指针，*p解指针，表示func5，返回值为数组a的首地址，顾后面解引用为a的第一个元素的值
    // cout<<p(a,3)<<" : "<<*(p(a,3))<<endl;   //与上面一行效果一致

    //定义一个指针数组，分别指向若干个函数
    int a[3] = {1,2,3};
    const int* (*parray[3])(int [],int) ={f1,f2,f3};
    cout<<(*parray[0])(a,3)<<" : "<<*((*parray[0])(a,3))<<endl;
    cout<<(parray[0])(a,3)<<" : "<<*((parray[0])(a,3))<<endl;   //与上面一行效果一致

    cout<<(*parray[1])(a,3)<<" : "<<*((*parray[1])(a,3))<<endl;
    cout<<(*parray[2])(a,3)<<" : "<<*((*parray[2])(a,3))<<endl;
    return 0;
}