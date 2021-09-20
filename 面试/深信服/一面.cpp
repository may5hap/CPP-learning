/**
 * @file 一面.cpp
 * @author whao
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 1、strlen() 和 sizeof() 的区别
 * 
 */

#include<iostream>
#include<string.h>
// #include<string>

using namespace std;

int main(){
    // string s1 = "1234567";
    // // cout << strlen(s1) << endl; // 这里会有问题，因为s1为c++风格字符串，但是strlen()的对象需要是c风格字符串
    // cout << strlen(s1.c_str()) << endl;
    // cout << sizeof(s1) << endl; // 这不会有问题

    const char * s2 = "1234";
    cout << strlen(s2) << endl;
    cout << sizeof(s2) << endl;
    return 0;
}