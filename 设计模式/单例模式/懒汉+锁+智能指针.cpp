#include<iostream>
#include<memory>
#include<mutex>

using namespace std;

class Singleton{
public:
    typedef shared_ptr<Singleton> ptr;
    //使用智能指针shared_ptr，运行结束时释放内存
    ~Singleton(){
        cout<<"析构函数调用"<<endl;
    }
    Singleton(Singleton&) =delete;
    Singleton& operator=(Singleton&) = delete;
    static ptr getinstance(){
        //双检查，在加锁前后都检查m_instance
        if(m_instance==nullptr){
            lock_guard<mutex> lk(m_mutex);
            if(m_instance==nullptr){
                m_instance = shared_ptr<Singleton>(new Singleton);
            }
        }
        return m_instance;
    }

private:
    Singleton(){
        cout<<"构造函数调用"<<endl;
    }
    static ptr m_instance;
    static mutex m_mutex;
};
shared_ptr<Singleton> Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;

int main(){
    shared_ptr<Singleton> instance = Singleton::getinstance();
    shared_ptr<Singleton> instance2 = Singleton::getinstance();
    cout << instance2.use_count() << endl;
    cout << instance.use_count() << endl;
    return 0;
}