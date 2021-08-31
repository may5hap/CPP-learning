#include<iostream>
#include<vector>
using namespace std;

/*  给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

    说明：每次只能向下或者向右移动一步。
*/

class Solution{
public:
    int m;
    int n;
    vector<vector<int> >mem;    //记忆化 
    int getShortestSum(vector<vector<int> > & grid){
        /* 方法1:dfs+记忆化*/
        m = grid.size();
        n = grid[0].size();
        mem = vector<vector<int> >(m,vector<int>(n,-1));    //初始化记忆    
        return dfs(0, 0, grid);
    }
    int dfs(int i, int j, vector<vector<int> > & grid){
        // i, j 表示当前位置，返回从当前位置到右下角的路径长度
        if(i<0 || i>=m || j<0 || j>= n) return INT_MAX; // 当前位置不能到达右下角
        if(mem[i][j] != -1) return mem[i][j];           // 已经记忆了当前位置到右下角的路径长度
        if(i == m-1 && j == n-1) return grid[i][j];     // 当前位置即右下角
        int right = dfs(i, j+1, grid);                  // 往右走到大右下角的最短路径长度
        int down = dfs(i+1, j, grid);                   // 往下走到大右下角的最短路径长度
        mem[i][j] = min(right,down) + grid[i][j];          // 当前位置到右下角的最短路径长度，记忆下来
        return mem[i][j];
    }

    int getShortestSum2(vector<vector<int> > & grid){
        /* *方法2:动态规划，与上面类似 */
        m = grid.size();
        n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n,-1));
        // 初始化
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-2; i>=0; i--){
            dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1];
        }
        for(int i = n-2; i>=0; i--){
            dp[m-1][i] = dp[m-1][i+1] + grid[m-1][i];
        }
        // 转移方程： dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
            }
        }
        return dp[0][0];
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
    cout << " ans = " << s.getShortestSum(grid) << endl;
    cout << " ans = " << s.getShortestSum2(grid) << endl;
    return 0;
}