#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    // cin >> s1;
    getline(cin, s1)
    for(decltype(s1.size()) idx = 0; idx < s1.size() && !isspace(s1[idx]); idx++){
        s1[idx] = toupper(s1[idx]);
    }
    cout << s1 << endl;
    return 0;
}