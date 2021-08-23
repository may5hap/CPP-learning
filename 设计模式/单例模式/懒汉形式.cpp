#include<iostream>

using namespace std;

class Singleton{
private:
    Singleton(){
        cout<<"构造函数调用"<<endl;
    }
    Singleton(Singleton& )=delete;
    Singleton& operator=(Singleton&)=delete;
    //delete关键字是c++11新加的，它可以禁用此函数
    static Singleton* m_instance;
public:
    ~Singleton(){
        cout<<"析构函数调用"<<endl;
    }
    static Singleton* getinstance(){
        if(m_instance==nullptr){
            m_instance = new Singleton();
        }
        return m_instance;
    }
    void use() const {
        cout<<"in use"<<endl;
    }
};
Singleton* Singleton::m_instance = nullptr;

int main(){
    Singleton* instance = Singleton::getinstance();
    instance->use();
    Singleton* instance2 = Singleton::getinstance();
    instance2->use();
    cout<<instance<<"   "<<instance2<<endl; //两个instance指向的是同一个地址，同一个对象，即只有一个对象，构造函数也只被调用了一次
    delete instance;
    return 0;
}