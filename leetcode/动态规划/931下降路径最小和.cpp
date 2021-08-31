#include<iostream>
#include<vector>
#include<climits>

using namespace std;

/*  * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径的最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

*/

/*  * 思路：
    * 此题依然是求最小路径和，不同的是引入一个下降路径的概念
    * 依然采用动态规划求解，设状态：dp[i][j] 为从位置i，j下降到最后一行的路径和
    * 所以最后一行的dp[i][j]等于matrix[i][j]
    * 但是，由于i，j的下一个位置涉及到j-1和j+1，故把dp矩阵设置的比matrix多两列，分别位于matrix的左右
    * 且多出来的两列的初值设置为INT_MAX,表示无法下降到最后一行
    * 转移方程： dp[i][j] = min( min(dp[i+1][j-1],dp[i+1][j]), dp[i+1][j+1])+ matrix[i][j]
*/

class Solution{
public:
    int minFallingPathSum(vector<vector<int> >& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > dp = vector<vector<int> >(m, vector<int>(n+2,INT_MAX));
        // 初始化
        for(int j = 1; j<n+1; j++){
            dp[m-1][j] = matrix[m-1][j-1];      // 这里需要是matrix[m-1][j-1],相当于把dp的一列一到最左边
        }
        for(int i = m-2; i>=0; i--){
            for(int j = 1; j<n+1; j++){
                dp[i][j] = min( min(dp[i+1][j-1],dp[i+1][j]), dp[i+1][j+1])+ matrix[i][j-1];
            }
        }
        int ans = INT_MAX;
        for(int j = 1; j<n+1; j++){
            ans = min(ans, dp[0][j]);
        }
        return ans;

    }

};

int main(){
    vector<vector<int> > grid;         
    int m, n;
    cout << "请输入表格行数和列数(空格隔开)：" << endl;
    cin >> m >> n;
    for(int i = 0; i<m; i++){
        cout << "请输入表格数据，每行" << n << "个数（空格隔开）：" <<endl;
        vector<int> tmp;
        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            tmp.push_back(k);
        }
        grid.push_back(tmp);
    }
    Solution s;
    cout << " ans = " << s.minFallingPathSum(grid) <<endl;
    return 0;
}