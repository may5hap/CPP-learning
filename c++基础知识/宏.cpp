#include<iostream>

#define MAX(x,y) (x>y? x : y)
#define MAX2(x,y) ((x)>(y)? (x):(y))
#define MAX3(x,y) ({typeof(x) _x = x; typeof(y) _y = y; _x>_y? _x : _y;})
//#define MAX4(x,y) ({typeof(x) _x = x; typeof(y) _y = y; (void)(&_x = &_y); _x>_y? _x : _y;})

using namespace std;

int main(){
    cout << MAX(1,2) << endl;
    cout << MAX2('1','2') << endl;
    
    int a = 1, b = 2;
    cout << MAX(a,b++) << endl;

    cout << MAX3(a,b++) << endl;

    //cout << MAX4('2',b) << endl;
    return 0;
}