#include<iostream>

using namespace std;

void test01(){
    int a = 10;
    long b = 20;
    b = static_cast<long> (a);
    b++;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}



void test02(){
    
}

int main(){
    test01();
    test02();
    return 0;
}