#include<iostream>
using namespace std;

class Operation{
public:
    int val1;
    int val2;
    virtual double getResult(){
        double res = 0;
        return res;
    }
};

class Add_operation: public Operation{
public:
    double getResult(){
        return val1+ val2;
    }
};

class Sub_Operation : public Operation{
public:
    double getResult(){
        return val1-val2;
    }
};

class Mul_Operation : public Operation{
public:
    double getResult(){
        return val1 * val2;
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
    virtual Operation* getOperation() = 0;
};

class Add_Factory: public Factory{
public:
    Operation* getOperation(){
        return new Add_operation();
    }
};

class Sub_Factory : public Factory{
public:
    Operation* getOperation(){
        return new Sub_Operation();
    }
};

class Mul_Factory : public Factory{
public:
    Operation* getOperation(){
        return new Mul_Operation();
    }
};

class Div_Factory: public Factory{
public:
    Operation* getOperation(){
        return new Div_Operation();
    }
};

int main(){
    int a = 10;
    int b = 20;

    //根据不同的需求，设计不同的工厂，均继承于最原始的工厂，在每个工厂内部实现对应的操作
    //乘法工厂
    Mul_Factory * mf = new Mul_Factory();
    Operation* mo = mf->getOperation();
    mo->val1 = a;
    mo->val2 = b;
    cout<< mo->getResult()<<endl;

    //除法工厂
    Div_Factory* df = new Div_Factory();
    Operation* doo = df->getOperation();
    doo->val1 = a;
    doo->val2 = b;
    cout<< doo->getResult() <<endl;
    return 0;
}