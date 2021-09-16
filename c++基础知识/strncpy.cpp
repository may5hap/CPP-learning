#include<iostream>
#include<string>

using namespace std;

char * myStrncpy(char * dst, const char* src, size_t count){
    char * tmp = dst;
    while(count--){
        if((*tmp = *src) != 0) src++;
        tmp++;
    }
    return dst;
}

int main(){
    const char * src = "wanghao";
    char dst[1024] = "";
    cout << myStrncpy(dst, src, 5) << endl;
    cout << sizeof(dst) << endl;
    return 0;
}