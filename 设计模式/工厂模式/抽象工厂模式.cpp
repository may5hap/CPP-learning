#include<iostream>
using namespace std;

//第一条产品线
class Product_pos{
public:
    int val1;
    int val2;
    virtual double getResult(){
        double res = 0;
        return res;
    }
};

class Add_Product_pos : public Product_pos{
public:
    double getResult(){
        return val1+ val2;
    }
};

class Sub_Product_pos : public Product_pos{
public:
    double getResult(){
        return val1-val2;
    }
};

class Mul_Product_pos : public Product_pos{
public:
    double getResult(){
        return val1*val2;
    }
};

class Div_Product_pos : public Product_pos{
public:
    double getResult(){
        return val1/val2;
    }
};

//第二条产品线
class Product_neg{
public:
    int val1;
    int val2;
    virtual double getResult(){
        double res = 0;
        return res;
    }
};

class Add_Product_neg : public Product_neg{
public:
    double getResult(){
        return -(val1 + val2);
    }
};

class Sub_Product_neg : public Product_neg{
public:
    double getResult(){
        return -(val1 - val2);
    }
};

class Mul_Product_neg : public Product_neg{
public:
    double getResult(){
        return -(val1*val2);
    }
};

class Div_Product_neg : public Product_neg{
public:
    double getResult(){
        return -(val1/val2);
    }
};

class Factory{
public:
    virtual Product_pos* createProduct_pos() = 0;
    virtual Product_neg* createProduct_neg() = 0;
};

class Add_Factory: public Factory{
public:
    Product_pos* createProduct_pos(){
        return new Add_Product_pos();
    }
    Product_neg* createProduct_neg(){
        return new Add_Product_neg();
    }
};

class Sub_Factory: public Factory{
public:
    Product_pos* createProduct_pos(){
        return new Sub_Product_pos();
    }
    Product_neg* createProduct_neg(){
        return new Sub_Product_neg();
    }
};

class Mul_Factory: public Factory{
public:
    Product_pos* createProduct_pos(){
        return new Mul_Product_pos();
    }
    Product_neg* createProduct_neg(){
        return new Mul_Product_neg();
    }
};

class Div_Factory: public Factory{
public:
    Product_pos* createProduct_pos(){
        return new Div_Product_pos();
    }
    Product_neg* createProduct_neg(){
        return new Div_Product_neg();
    }
};

int main(){
    int a = 20;
    int b = 10;

    //乘法工厂，在乘法工厂中，制造需要的产品或方法
    Mul_Factory* mf = new Mul_Factory();
    Product_pos* pp = mf->createProduct_pos();
    pp->val1 = a;
    pp->val2 = b;
    cout<< pp->getResult() << endl;

    //除法工厂
    Div_Factory* df = new Div_Factory();
    Product_neg* pn = df->createProduct_neg();
    pn->val1 = a;
    pn->val2 = b;
    cout<< pn->getResult() << endl;
    return 0;
}