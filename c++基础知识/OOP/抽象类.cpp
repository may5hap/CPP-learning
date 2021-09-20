#include<iostream>

using namespace std;

class Base{
public:
    virtual void Print() = 0;
};

class Derived:public Base{
public:
    void Print(){
        cout << "Derived" << endl;
    }
};

int main(){
    Derived d;
    d.Print();

    Base *b = new Derived();
    b->Print();
    return 0;
}