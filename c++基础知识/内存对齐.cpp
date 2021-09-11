#include<iostream>

using namespace std;

struct data{
    int a;
    short b;
    char c;
};

int main(){
    cout << sizeof(data) << endl;
    return 0;
}