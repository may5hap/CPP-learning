/**给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
*/

/**分析
 * 求最少操作数，典型的动态规划问题，要求word1和word2的编辑距离，假定长度分别为m,n,则最后求出来的dp[m][n]即为最后答案
 * 由此，可以定义状态：dp[i][j]表示word1的前i个字符构成的子字符串和word2的前j个字符构成的子字符串的编辑距离
 * 所以，状态转移方程：dp[i][j] = min(  min(dp[i-1][j],  dp[i][j-1]),   dp[i-1][j-1]) + 1
 *                                   ｜                ｜                   ｜
 *                   删除word1的第i个字符  将word2的第j个字符插入word1的i位置  用word2的第j个字符替换word1的第i个字符  
 * 
 * 上述方程在word1[i-1]!=word2[j-1]时成立
 * 如果word1[i-1]==word2[j-1]，则表明当前字符匹配，dp[i][j] = dp[i-1][j-1]
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    int leastOperation(string s1, string s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        // 初始化，dp[i][0] = i   dp[0][i] = i   dp[0][0] = 0
        for(int i = 1; i<=m; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j<=n; j++){
            dp[0][j] = j;
        }

        // 转移方程
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;
    string s1, s2;
    cout << "请输入第一个字符串：" << endl;
    cin >> s1;
    cout << "请输入第二个字符串"  <<endl;
    cin >> s2;
    cout << "编辑距离为：" << s.leastOperation(s1,s2) <<endl;
    return 0;
}