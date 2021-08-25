#include<iostream>
#include<list>

using namespace std;

class Subject;  //被观察者

class Observer{
protected:
    string Observername;    //观察者名字
    Subject* sub;           //指向被观察者的指针
public:
    Observer(string _name, Subject* _sub){
        this->Observername = _name;
        this->sub = _sub;
    }
    virtual void update() = 0;  //观察者纯虚函数，抽象类，不同的观察者重写此函数
};

class Observer1: public Observer{       //派生出来的第一类观察者
public:
    Observer1(string _name, Subject* _sub): Observer(_name,_sub){}
    void update();
};

class Observer2: public Observer{
public:
    Observer2(string _name, Subject* _sub): Observer(_name,_sub){}
    void update();
};

class Subject{
public:
    string state;                               //被观察者状态
    virtual void attach(Observer* ob) = 0;      //关联观察者
    virtual void detach(Observer* ob) = 0;      //取消拉黑观察者
    virtual void notify() = 0;                  //将被观察者状态的改变通知所有的观察者
protected:
    list<Observer*> obs;                        //所有的观察者
};

class Secretary: public Subject{
public:
    void attach(Observer* ob){
        obs.push_back(ob);
    }
    void detach(Observer* ob){
        auto it = obs.begin();
        while(it++!=obs.end()){
            if(*it==ob){
                obs.erase(it);
                return;
            }
        }
    }
    void notify(){
        auto it = obs.begin();
        while(it!=obs.end()){
            (*it)->update();
            it++;
        }
    }
};

void Observer1::update(){
    cout << Observername << "收到消息" << sub->state << endl;
    if(sub->state == "班主任来了"){
        cout << "停止瞌睡，开始看书" << endl;
    }
}

void Observer2::update(){
    cout << Observername << "收到消息" << sub->state << endl;
    if(sub->state == "班主任来了"){
        cout << "停止打游戏，开始看书" << endl;
    }
}

int main(){
    Subject * s = new Secretary();              //多态，父类指针指向子类对象
    Observer* ob1 = new Observer1("张三",s);    //多态，父类指针指向子类对象
    Observer* ob2 = new Observer2("李四",s);    //多态，父类指针指向子类对象
    s->attach(ob1);
    s->attach(ob2);
    s->state = "班主任来了";
    s->notify();
    s->state = "班主任走了";
    s->notify();
    return 0;
}