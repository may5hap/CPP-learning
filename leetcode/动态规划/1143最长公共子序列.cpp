/**题目：给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列 是指这样一个新的字符串：
 * 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
 * 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。 * 
*/

/**分析：
 * 典型的动态规划题目，首先设计状态，由于要求的是两个字符串的最长公共子序列，设m为text1的长度，n为text2的长度
 * 那么dp[m][n]就应该是所求的结果，dp[i][j]就是text1[0,1...i]与text2[0,1,...j]的最长公共子序列
 * 递推关系如何呢？
 * 如果text1[i]==text2[j]，那么dp[i][j]=dp[i-1][j-1]+1，表示当前两个字符串的当前字符是匹配的
 * 如果text1[i]！=text2[j]，dp[i][j]并不是等于dp[i-1][j-1]，因为有可能text1[i]==text2[j-1]或者text1[i-1]==text2[j]
 * 所以当text1[i]！=text2[j]时，dp[i][j]=max(dp[i][j-1],dp[i-1][j])
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int LCS(string text1,string text2){
        int m = text1.size();
        int n = text2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        // 初始化，dp[i][0]=0,dp[0][j]=0，因为当有一个长度为0时，结果就是0,这一步在上面一行已经完成
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int main(){
    string s1, s2;
    cout << "请输入两个字符串" <<endl;
    cin >> s1 >> s2;
    Solution s;
    cout << "你输入的两个字符串的最长公共子序列长度为：" << s.LCS(s1,s2) << endl; 
    return 0;
}