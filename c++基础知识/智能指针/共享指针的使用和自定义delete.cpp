//shared_ptr默认的删除方式是用delete，但是它并不能有效删除数组等类型
//可以自定义delete类或者利用lambda函数

#include<iostream>
#include<memory>
using namespace std;

//自定义的删除器模版
template<class T>
class deletor{
public:
    void operator()(T * arr){
        cout<<"自定义deletor"<<endl;
        delete[] arr;
    }
};

class Sample{
public:
    Sample(){cout<<"Sample构造函数"<<endl;}
    ~Sample(){cout<<"Sample析构函数"<<endl;}
};

void deleter(Sample * arr){
    cout<<"函数deleter"<<endl;
    delete[] arr;
}
int main(){
    //Sample* ar = new Sample[3];
    shared_ptr<Sample> p1 = make_shared<Sample>();
    p1.reset();
    cout<<p1.use_count()<<endl;
    p1.reset(new Sample());
    cout<<p1.use_count()<<endl;
    
    shared_ptr<Sample> p2(new Sample[3],deletor<Sample>());

    shared_ptr<Sample> p3(new Sample[2],deleter);
    shared_ptr<Sample> p4(p3);
    cout<<p3.use_count()<<endl;
    cout<<p4.use_count()<<endl;
    //p3和p4指向同一个地址空间
    cout<<"p3的值："<<p3<<endl;
    cout<<"p4的值："<<p4<<endl;

    return 0;
}