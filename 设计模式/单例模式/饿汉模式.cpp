#include<iostream>

using namespace std;

class Singleton{
private:
    Singleton(){
        cout<<"构造函数调用"<<endl;
    }
    Singleton(Singleton&) =delete;
    Singleton& operator=(Singleton&) =delete;
    static Singleton * m_instance;
public:
    static Singleton* getinstance(){
        return m_instance;
    }
    ~Singleton(){
        cout<<"析构函数调用"<<endl;       
    }
};
Singleton* Singleton::m_instance = new Singleton();

int main(){
    Singleton* instance = Singleton::getinstance();
    Singleton* instance2 = Singleton::getinstance();
    delete instance;
    return 0;
}