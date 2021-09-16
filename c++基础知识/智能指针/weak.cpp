#include<iostream>
#include<memory>

using namespace std;

int main(){
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2(p1);
    weak_ptr<int> p3(p2);
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p1.use_count() << endl;
    cout << *p2 << endl;

    cout << p3.use_count() << endl;

    // p3.reset();
    // cout << p3.use_count() << endl;

    // p2.reset();
    // cout << p3.use_count() << endl;

    shared_ptr<int> p4 = p3.lock();
    cout << p4.get() << endl;
    cout << p3.use_count() << endl;
    return 0;
}