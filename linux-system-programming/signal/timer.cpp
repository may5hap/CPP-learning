#include<unistd.h>
#include<iostream>

using namespace std;

int main(){
    alarm(1);
    int i = 0;
    while(1){
        cout << i<<endl;
        i++;
    }

}