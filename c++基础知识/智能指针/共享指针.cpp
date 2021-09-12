#include<iostream>
using namespace std;

template<class T>
class my_shared_ptr{
    //对shared_ptr的实现
    //主要包括两个指针，一个指向对象，一个计数
    //构造函数，默认构造，拷贝构造
    //运算符重载 * -> =
public:
    T* obj;
    int* cnt;
    my_shared_ptr(T* _obj):obj(_obj){
        if(obj!=nullptr) 
            cnt = new int(1);
        else 
            cnt = new int(0);
        cout<<"构造函数my_shared_ptr(T* _obj)"<<endl;
    }
    //拷贝函数构造
    my_shared_ptr(const my_shared_ptr& a){
        if(this!=&a){
            this->obj = a.obj;
            this->cnt = a.cnt;
            (*this->cnt)++;
            cout<<"构造函数my_shared_ptr(const my_shared_ptr& a)"<<endl;
        }
    }
    //赋值运算符重载
    my_shared_ptr& operator=(const my_shared_ptr& a){
        if(this->obj == a.obj) return *this;
        if(this->obj!=nullptr){
            (*this->cnt)--;
            if((*this->cnt)==0){
                delete this->obj;
                delete this->cnt;
            }
        }
        this->obj = a.obj;
        this->cnt = a.cnt;
        cout<<"赋值运算符重载"<<endl;
        return *this;
    }
    //析构函数
    ~my_shared_ptr(){
        (*this->cnt)--;
        if((*this->cnt)==0){
            delete this->obj;
            delete this->cnt;
        }
        cout<<"析构函数"<<endl;
    }
    //运算符 * 重载
    T& operator*(){
        assert(this->obj!=nullptr);
        return *(this->obj);
    }
    //运算符 -> 重载
    T* operator->(){
        assert(this->obj != nullptr);
        return this->obj;
    }
    //一个函数，显示现在拥有这个共享指针的数量
    int use_count(){
        return *(this->cnt);
    }
};

int main(){
    my_shared_ptr<int> p1(new int(1));    
    //my_shared_ptr<int> p1 = new int(1);
    cout << p1.use_count()<<endl;
    my_shared_ptr<int> p2(p1);
    cout << p1.use_count()<<endl;
    cout << p2.use_count()<<endl;
    my_shared_ptr<int> p3 = p2;
    cout << p1.use_count()<<endl;
    cout << p2.use_count()<<endl;
    cout << p3.use_count()<<endl;
    cout << &p1 << " " << &p2 << " " << &p3 << endl;
    cout << *p1 << " " << *p2 << " " << *p3 << endl;
    return 0;
}