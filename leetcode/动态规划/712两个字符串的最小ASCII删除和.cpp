/**题目：给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。
 * 输入: s1 = "delete", s2 = "leet"
 * 输出: 403
 * 解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
 * 将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
 * 结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
 * 如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
*/

/**分析：
 * 与最长公共子序列类似，是其延伸
 * 思路一致：
 * dp[i][j]表示s1的前i个字符组成的字符串和s2的前j个字符组成的字符串所需要删除字符的ASCII值
 * 则分析递推关系：
 * 1、如果s1[i]==s2[j],那么dp[i][j]=dp[i-1][j-1],表示当前字符相同，不需要删除
 * 2、如果s1[i]!=s2[j],那么可以选择删除s1[i]或者s2[j]:
 *      a：删除s1[i]：dp[i][j] = dp[i-1][j] + s1[i]
 *      b：删除s2[j]: dp[i][j] = dp[i][j-1] + s2[j]
 * 所以dp[i][j] = min(dp[i-1][j] + s1[i],dp[i][j-1] + s2[j])
 * 注意此时的初始化也有变化，因为如果有一个字符串长度为0，则需要删除另一个字符串所有字符
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int minSum(string s1,string s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        // 初始化：dp[0][0] = 0
        for(int i = 1; i<=m; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j = 1; j<=n; j++) dp[0][j] = dp[0][j-1] + s2[j-1];
        // 递推：
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
    }
};

int main(){
    string s1,s2;
    cout << "请输入两个字符串：" <<endl;
    cin >> s1 >> s2;
    Solution s;
    cout << "最小ASCII删除和：" << s.minSum(s1,s2) << endl;
    return 0;
}