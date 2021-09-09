#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    string curPath = "\\";
    string command;
    string s;
    string args;
    cin >> n;
    getchar();
    int cnt = 0;
    while(getline(cin,s)){
        // cin >> s;
        cnt++;
        int emp = s.find(" ");
        if(emp==string::npos){
            // 执行pwd
            // cout << s << endl;
            cout << curPath << endl;
        }
        else{
            // 执行cd
            command = s.substr(0, emp);
            args = s.substr(emp+1,s.size()-emp);
            // cout << command << endl;
            // cout << args<< endl;
            if(args==".."){
                int last = curPath.rfind("\\");
                curPath = curPath.substr(0,last);
                if(curPath.empty()) curPath = "\\";
            }
            else{
                if(curPath=="\\"){
                    curPath += args;
                }
                else{
                    curPath += "\\";
                    curPath += args;
                }
            }
        }
        if(s.empty() || cnt == n) break;
    }
    return 0;

}