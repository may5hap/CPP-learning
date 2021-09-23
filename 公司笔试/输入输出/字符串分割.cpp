#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    vector<string> data;
    size_t pos = s.find(",");
    while(pos!=string::npos){
        string tmp;
        tmp = s.substr(0,pos);
        data.push_back(tmp);
        s = s.substr(pos+1);
        pos = s.find(",");
    }
    data.push_back(s);
    for(string x:data){
        cout << x << endl;
    }
    return 0;
}