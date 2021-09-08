/**
 * @file 华为真题输入测试.cpp
 * @author whao
 * @brief 
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**扑克牌，输入格式：
 * 4 4 4 4-A A
 * J J-JOKER joker
 */

#include<iostream>
#include<string>

using namespace std;

int main(){
    // string s1, s2;
    char s1[20];
    char s2[20];
    cin.getline(s1, 20, '-');   // 表示以'-'为
    cin.getline(s2, 20);
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}