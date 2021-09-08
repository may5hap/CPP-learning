#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s.size()==0) break;
        cout << s<< endl;
    }
    return 0;
}