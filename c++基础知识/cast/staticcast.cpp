#include<iostream>

using namespace std;

void test01(){
    int a = 10;
    long b = 20;
    b = static_cast<long> (a);
    b++;
    cout << "test01" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

class A{
public:
    string name;
    A():name("class A"){}
    void cname(){
        cout<< "name = " << name<< endl;
    }
};

class B: public A{
public:
    string name;
    string _type;
    B():name("class B"),_type("B type"){}
    void c_type(){
        cout << "_type = " << _type<< endl;
    }
};

void test02(){
    // A * a = new A();
    // B * b = new B();

    cout << "test02()" << endl;

    // up cast
    /*a = static_cast<A*> (b);
    a->cname();
    b->cname();
    b->c_type();8?
    /* A */

    //down cast
    /*b = static_cast<B*> (a);
    a->cname();
    b->cname();
    b->c_type();*/

    A * a = new B();
    a->cname();
}

int main(){
    test01();
    test02();
    return 0;
}