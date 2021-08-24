#include<iostream>
using namespace std;

/* * 主要用于创建对象，一个工厂根据输入的不同，产生不同德的类，得到不同的结果 */

class Operation{
public:
    int val1;
    int val2;
    virtual double getResult(){
        double res = 0;
        return res;
    }
};

class Add_Operation: public Operation{
public:
    double getResult(){
        return val1+val2;
    }
};

class Sub_Operation: public Operation{
public:
    double getResult(){
        return val1-val2;
    }
};

class Mul_Operation: public Operation{
public:
    double getResult(){
        return val1*val2;
    }
};

class Div_Operation: public Operation{
public:
    double getResult(){
        return val1/val2;
    }
};

class Factory{
public:
    static Operation* get_operation(const char op){
        switch (op)
        {
        case '+':
            return new Add_Operation();
        
        case '-':
            return new Sub_Operation();
        
        case '*':
            return new Mul_Operation();

        case '/':
            return new Div_Operation();

        default:
            return new Add_Operation();
        }
    }
};

int main(){
    int a = 10, b = 20;
    //cin >> a>> b;
    Operation* add = Factory::get_operation('+');   //父类指针指向子类对象
    //通过类名::静态函数调用，返回Operation父类指针，指向Add_Operation子类对象
    add->val1 = a;
    add->val2 = b;
    cout<< add->getResult() << endl;
    

    Operation* sub = Factory::get_operation('-');
    sub->val1 = a;
    sub->val2 = b;
    cout<<sub->getResult()<<endl;
    return 0;
}