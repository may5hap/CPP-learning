#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));   // dp[i][j]表示从i到j的子串是回文子串
        pair<int,int> ans;
        for(int i =0 ;i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j) dp[i][j] = true;
                else if(i-j==1 && s[i]==s[j]) dp[i][j] = true;
            }
        } 
        for(int i = n-2; i< n; i++){
            for(int j = i+1; j<n; j++){
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = false;
                if(dp[i][j] && j-i>ans.second-ans.first){
                    ans.first = i;
                    ans.second = j;
                }
            }
        }
        return s.substr(ans.first,ans.second-ans.first);

    }
};

int main(){
    cout << "请输入你的字符串："  << endl;
    string s;
    cin >> s;
    Solution sol;
    string ans = sol.longestPalindrome(s);
    cout << ans << endl;

    return 0;
}