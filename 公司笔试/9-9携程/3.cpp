#include<iostream>
#include<string>
#include<vector>

using namespace std;

// vector<string> handleInput(string s, int n){
//     vector<string> ans;
//     while(s.find("0")!=string::npos){
//         int pos = s.find("0");
//         ans.push_back(s.substr(0,pos));
//         s = s.substr(pos+1);
//     }
//     // string subStr = "";
//     // for(int i = 0; i<n; i++){
//     //     if(s[i]!='0') subStr.push_back(s[i]);
//     //     else{
//     //         ans.push_back(subStr);
//     //         subStr = "";
//     //     }
//     // }
//     // if(!subStr.empty()) ans.push_back(subStr);
//     return ans;
// }

int getSubOptimal(string& S, vector<int>& v1, vector<int>& v2){
    int n = S.size();
    vector<int> dp(n+1,0);
    for(int i = 1; i<=n; i++){
        for(int k = 0; k<v1.size(); k++){
            if(i>=v1[k]) dp[i] = max(dp[i], (dp[i-v1[k]] + v2[k]));
        } 
    }
    return dp[n];
}

int solve(vector<string>& ss, vector<int>& v1, vector<int>& v2){
    int ans = 0;
    for(int i = 0; i<ss.size(); i++){
        int a = getSubOptimal(ss[i], v1, v2);
        ans += a;
        cout << a << endl;
    }
    return ans;
}

int main(){
    int n,m;
    string s = "";
    vector<int> v1; // 存储k
    vector<int> v2; // 存储x
    vector<string> ss;
    cin >> n >> m;
    char ch;
    int cnt = 0;
    getchar();
    while(scanf("%c", &ch)){
        cout << ch << endl;
        cnt++;
        if(ch=='1') s.push_back(ch);
        if(ch=='0'){
            ss.push_back(s);
            cout << s << endl;
            s = "";
        }
        if(cnt==n) {
            ss.push_back(s);
            cout << s<< endl;
            break;
        }
    }
    cnt = 0;
    int k,x;
    while(cin >> k >> x){
        cnt++;
        v1.push_back(k);
        v2.push_back(x);
        cout << v1.back() << endl;
        cout << v2.back() << endl;
        if(cnt==m) break;
    }
    int ans = solve(ss, v1, v2);
    cout << ans << endl;
    return 0;
}