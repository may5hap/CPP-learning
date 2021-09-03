/**题目：
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列
*/

/**分析：
 * 根据回文串的性质，左右两端的字符相同
 * 设置状态：dp[i][j]表示s[i,..,j]子串中最长回文子序列的长度
 * 那么很显然：
 * 1、如果s[i]==s[j]，那么dp[i][j] = dp[i+1][j-1] + 2
 * 如果s[i]!=s[j]，说明，在s[i,...,j]中，s[i]和s[j]不能同时出现做为回文字符串，所以有两种情况：
 *      a:s[i]出现在回文字符串中，那么dp[i][j]=dp[i][j-1]
 *      b:s[j]出现在回文字符串中，那么dp[i][j]=dp[i+1][j]
 * 所以：
 * 2、如果s[i]!=s[j]，那么dp[i][j] = max(dp[i][j-1],dp[i+1][j])
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int longest(string s){
        int n = s.size();
        vector<vector<int> > dp(n,vector<int>(n,0));
        // 初始化：dp[i][i]=1，表示从i开始到从i结束的子字符串的最大回文串长度为1
        for(int i = 0; i<n; i++) dp[i][i] = 1;
        // 递推：(注意，i>j时，dp[i][j]=0)
        for(int i = n - 2; i>=0; i--){
            // i=n-1行已经算好
            for(int j = i + 1; j<n; j++){
                // 在DP Table中，元素往右上角收缩，注意便利方式 **
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    string s;
    cout << "请输入你的字符串" <<endl;
    cin >> s;
    Solution solution;
    cout << "最长回文子序列长度为：" <<solution.longest(s) <<endl;
    return 0;
}