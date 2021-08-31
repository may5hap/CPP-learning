#include<iostream>
#include<vector>

using namespace std;

/*
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。
我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；
其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
*/

/*
    * 此题与64最小路径和类似，利用逆向思维比较好求解
*/

class Solution{
public:
    int getMinHP(vector<vector<int> > & grid){
        /*  * 动态规划，dp[i][j]表示从i，j到公主位置需要的最少血量 
            * 则dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - grid[i][j]
            * 表明，在i，j的位置所需要的血量等于，从下和从右解救公主所需要血量的最少值减去在i，j所获得的血量（有正负）
            * 但是有可能dp[i][j]小于等于0，题说小于等于0则骑士死亡，此时所需要的最少血量为1
            * 综上，dp[i][j] = max( min(dp[i+1][j],dp[i][j+1]) - grid[i][j], 1)
        */
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dp = vector<vector<int> >(m, vector<int>(n,0));
        // 初始化
        dp[m-1][n-1] = grid[m-1][n-1]>=0? 1 : -grid[m-1][n-1]+1;
        for(int i = m-2; i>=0; i--){
            dp[i][n-1] = max(dp[i+1][n-1]-grid[i][n-1],1);
        }
        for(int j = n-2; j>=0; j--){
            dp[m-1][j] = max(dp[m-1][j+1]-grid[m-1][j],1);
        }
        // 转移方程
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = max(min(dp[i+1][j],dp[i][j+1]) - grid[i][j], 1);
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
    cout << " ans = " << s.getMinHP(grid) <<endl;
    return 0;
}