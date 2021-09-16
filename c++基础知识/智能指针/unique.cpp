#include<iostream>
#include<memory>
using namespace std;

void deleter(int * arr){
    delete[] arr;
}

int main(){
    unique_ptr<int> p1(new int(100));
    cout << p1.get() << endl;       // 获取p1的值（变量地址）
    cout << *p1.get() << endl;      // 解地址

    /*int a  = 1;
    int * pa = &a;
    unique_ptr<int> p2(pa);
    cout << pa << endl;
    cout << p2.get() << endl;*/
    // 不要像上面那样，上面的操作首先将pa指向a，然后用pa初始化unique_ptr，
    // 这就导致有多个指针指向变量a，不符合unique_ptr的独占特性，在释放内存时，导致内存多次释放

    unique_ptr<int> p2(new int(10));
    cout << p2.get() << endl;
    // unique_ptr<int> p3 = p2; // 错误，不符合unique_ptr的独占特性，如果需要这样的赋值，需要用move：
    unique_ptr<int> p3 = move(p2);
    cout << p2.get() << endl;   // 使用move之后，p2为空，其值赋给了p3，p3将独占管理
    cout << p3.get() << endl;
    p3.reset();
    cout << p3.get() << endl;   // p3指向空
    p3.reset(new int(100));
    cout << p3.get() << endl;   // 这时候，p3还是之前的地址

    // cout << p3.release() << endl;   // 释放控制权，返回值为地址（指针）
    // cout << p3.get() << endl;       // 释放之后，p3置为空

    unique_ptr<int> p5(p3.release());   // 所以可以这样操作
    cout << p5.get() << endl;
    cout << *p5.get() << endl;


    unique_ptr<int[]> p4(new int[3]);
    cout << p4.get() << endl;
    cout << &p4[0] << endl;
    cout << &p4[1] << endl;
    cout << &p4[2] << endl;

    return 0;
}