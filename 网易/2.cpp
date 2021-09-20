#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(string s, int m){
    int n = s.size();
    vector<int> dp(n,1);
    if(m==0){
        for(int i = 1; i<n; i++){
            dp[i] = dp[i-1] + s[i] - s[i-1] + 1;
        }
    }
    else{
        for(int i = 1; i<m; i++){
            dp[i] = dp[i-1] + s[i] - s[i-1] + 1;
        }
        for(int i = m; i<n; i++){
            dp[i] = min(dp[i-1] + s[i] - s[i-1] + 1, dp[i-m]+2*m);
        }
    }
    return dp[n-1];
}

int main(){
    int m;
    string s;
    string inp;
    getline(cin, inp);
    int l = inp.size();
    int pos = inp.find(" ");
    s = inp.substr(0,pos);
    // cout << s<< endl;
    m = atoi(inp.substr(pos+1,l-pos-1).c_str());
    // cout << m << endl;
    int ans = solve(s,m);
    cout << ans << endl;
    return 0;
}