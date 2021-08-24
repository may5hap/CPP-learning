#include<iostream>
#include<cstring>
using namespace std;

//通用函数模版
template<class T>
bool equal(const T a, const T b){
    cout<<"通用函数模版:";
    return a==b;
}

//特化函数模版
template<>      //这里<>里面没有任何参数，告诉编译器这是特化的函数模版
bool equal(char* a, char* b){
    cout<<"特化函数模版:";
    return strcmp(a,b)==0;
}

int main(){
    int a = 10, b =10;
    cout<<equal(a,b)<<endl;
    char arr1[] = "123";
    char arr2[] = "123";
    cout<<equal(arr1,arr2)<<endl;
    return 0;
}