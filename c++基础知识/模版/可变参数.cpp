#include <iostream>

using namespace std;

template <typename T>
void print_fun(const T &t)
{
    cout << "无可变参数函数调用" << t << endl; // 最后一个元素
}

template <typename T, class... a>
void print_fun(const T &t, const a &...args)
{
    cout << "有可变参数函数调用" << t << endl;
    print_fun(args...);     //递归调用，当只有最后一个参数时，调用无可变参数函数
}

int main()
{
    string a = "hello";
    string b = "world";
    string c = "!!!!!";
    print_fun(a);
    print_fun(a,b,c);
    return 0;
}