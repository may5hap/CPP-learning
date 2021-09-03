/**题目：
 * 给定两个单词 word1 和 word2，
 * 找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。
 * 比如： sea 和 eat 所需要删除的操作次数为2
*/

/**分析：
 * 两个字符串删除一些自负之后，剩下的就是两个字符串公共部分，所以可以转化成最长公共子序列的问题
 * 假设两个字符串的最长公共子序列长度为2，则需要删除的次数为m+n-2*2
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int leastErase(string s1,string s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return m+n-2*dp[m][n];
    }
};

int main(){
    string s1,s2;
    cout << "请输入两个字符串：" <<endl;
    cin >> s1 >> s2;
    Solution s;
    cout << "最少需要进行：" << s.leastErase(s1,s2) << " 步删除操作"  << endl;
    return 0;
}
