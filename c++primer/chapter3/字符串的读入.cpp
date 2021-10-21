#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    // cin >> s1;
    // cout << s1 << endl;

    // cin >> s1 >> s2;
    // cout << s1 << " " << s2 << endl;

    // while(cin >> s1){
    //     cout << s1 << endl;     // 按 ctrl + c 终止输入
    // }

    /**
     * @brief 如果想要保留读入的字符串中的空格，可用getline()函数
     * 
     */
    while(getline(cin, s1)){
        cout << s1 << endl;
    }

    return 0;
}