#include<iostream>

using namespace std;

class Test{
private:
    int m_valude;

public:
    Test(int n){
        cout << "Test(int)" <<endl;
        m_valude = n;
    }
    Test(const Test& other){
        //only can be const & ?
        cout << "Test(Test& other)" <<endl;
        m_valude = other.m_valude;
    }
    void Print(){
        cout<<m_valude<<endl;
    }
};

int main(){
    cout << "1: ";
    Test a = 1;
    a.Print();
    cout << "2: ";
    Test b = a;
    b.Print();
    return 0;
}