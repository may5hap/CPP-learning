#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool valid(int k){
    if(k == 1 || k == 2) return true;
    bool flag = true;   // 是一个素数
    for(int i = 2; i<=k/2; i++){
        if(k%i == 0){
            flag = false;
            break;
        } 
    }
    return flag;
}

int n;
vector<int> ans;

void dfs(string & s, int i, vector<string> tmp){
    if(i==s.size()-1){
        if(tmp.size()>n){
            n = tmp.size();
            ans.clear();
            for(string ss:tmp){
                ans.push_back(atoi(ss.c_str()));
            }
        }
        return;
    } 

    for(int j = 1; j<5; j++){
        if(valid(atoi(s.substr(i,j).c_str()))){
            tmp.push_back(s.substr(i,j));
            dfs(s,i+j,tmp);
            tmp.pop_back();
        }
    }
}

int main(){
    string s;
    cin >> s;
    vector<string> path;
    dfs(s,0,path);
    cout << n << endl;
    for(int i = 0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}