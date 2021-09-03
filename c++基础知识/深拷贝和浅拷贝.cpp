/**当出现类的等号赋值时，会调用拷贝函数，在未定义显示拷贝构造函数的情况下， 系统会调用默认的拷贝函数－即浅拷贝，
 * 它能够完成成员的一一复制。当数据成员中没有指针时，浅拷贝是可行的。\
 * 当数据成员中有指针时，如果采用简单的浅拷贝，则两类中的两个指针指向同一个地址，当对象快要结束时，
 * 会调用两次析构函数，而导致指野指针的问题。
 * 所以，这时必需采用深拷贝。深拷贝与浅拷贝之间的区别就在于深拷贝会在堆内存中另外申请空间来存储数据，
 * 从而也就解决来野指针的问题。简而言之，当数据成员中有指针时，必需要用深拷贝更加安全。
*/

#include<iostream>

using namespace std;

// 浅拷贝
// class Test{
// public:
//     int m_a;
//     char * m_p;
//     Test():m_a(0),m_p(nullptr){
//         cout << "无参构造函数" << endl;
//     }
//     Test(int a, char* p):m_a(a),m_p(p){
//         cout << "普通构造函数" <<endl;
//     }
//     Test(const Test& t){
//         cout << "拷贝构造函数(浅拷贝)" << endl;
//         this->m_a = t.m_a;
//         this->m_p = t.m_p;
//     }
//     Test& operator=(const Test& t){
//         cout << "赋值运算符重载" << endl; 
//         this->m_p = t.m_p;
//         this->m_a = t.m_a;
//         return *this;
//     }
//     ~Test(){
//         cout << "析构函数  " << m_a << "   " << *(m_p) << endl;
//         delete m_p;
//     }
// };

// 深拷贝
class Test{
public:
    int m_a;
    char * m_p;
    Test():m_a(0),m_p(nullptr){
        cout << "无参构造函数" << endl;
    }
    Test(int a, char* p):m_a(a),m_p(p){
        cout << "普通构造函数" <<endl;
    }
    Test(const Test& t){
        cout << "拷贝构造函数(深拷贝)" << endl;
        this->m_a = t.m_a;
        if(this->m_p!=t.m_p){
            if(this->m_p!=nullptr){
                *m_p = *(t.m_p);
            }
        }
    }
    Test& operator=(const Test& t){
        cout << "赋值运算符重载" << endl; 
        this->m_a = t.m_a;
        if(this!=&t){
            this->m_p = t.m_p;
        }
        return *this;
    }
    ~Test(){
        cout << "析构函数  " << m_a << "   " << *(m_p) << endl;
        delete m_p;
    }
};

int main(){
    /* * 浅拷贝测试 * */
    char ch = 'w';
    Test *t1 = new Test(1, &ch);
    Test t2(*t1);
    t2.m_a+=1;
    delete t1;
    return 0;
}