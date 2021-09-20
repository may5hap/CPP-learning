#include<iostream>

using namespace std;

struct data{
    int a;
    short b;
    char c;
};

struct data1{
    char a;
    long b;
    char c;
    double d;
};

int main(){
    cout << sizeof(data) << endl;
    cout << sizeof(data1) << endl;
    cout << sizeof(double) << endl;
    return 0;
}