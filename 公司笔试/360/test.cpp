#include<iostream>
#include<limits.h>
using namespace std;

int main(){

    int a[4][3] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*ptr)[3] = a;
    cout << *(*(a+1)+2) << endl;
    cout << *(*(ptr+2)) + 1 << endl;
    // int a = INT_MAX;
    // INT64_MAX;
    cout << (int*)"hello world";
    return 0;
}