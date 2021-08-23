#include <iostream>
using namespace std;

class A{};

int main(void)
{
    int a = 10;
    int * p1 = &a;
    char * p2 = nullptr;
    A * p3 = new A();
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    return 0;
}
