#include<iostream>

using namespace std;

void test01(){
    //test for convert pointer, it doesnot really change
    const int a = 10;
    int * p;
    p = const_cast<int*> (&a);
    (*p)++;
    cout<< "a = " << a << endl;
    cout<< "*p = " << *p << endl;
}

void test02(){
    //test for convert reference, it doesnot really change
    const int a = 10;
    int &b = const_cast<int &> (a);
    b++;
    cout<< "a = " << a << endl;
    cout<< "b = " << b << endl;
}

int main(){
    test01();
    test02();
    return 0;
}