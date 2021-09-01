/**给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

    请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

    假设每一种面额的硬币有无限个。 

    题目数据保证结果符合 32 位带符号整数。
 * 典型的完全背包问题
 * 方法1、基础解法：
 * 完全背包问题是0-1背包问题的进阶版，在0-1背包中，每个硬币只有一个，只能选或不选
 * 在完全背包中，每个硬币有无穷多个，故在0-1的基础上，可以推导出动态规划递推关系式为：
 * dp[i][j]表示前i中硬币可以组成总金额为j的组合数（有多少种）
 * 那么：   dp[i][j] = dp[i-1][j] + dp[i-1][j-coins[i-1]] + dp[i-1][j-2*coins[i-1]] + dp[i-1][j-3*coins[i-1]] + ...
 * 上式可以理解为：          ｜                 ｜                      ｜                          ｜
 *                  选择0个第i种硬币      选择1个第i种硬币          选择2个第i种硬币               选择3个第i中硬币      ...
 * 
*/

/**方法2
 * 进阶1：
 * 上面的做法需要三个循环，分别对i、j和第i种硬币个数k做循环，效率很低
 * 换个角度理解问题：   dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
 * 表示当前可以的选择是：选择0个第i种硬币，选择1个第i种硬币之后，再在前i种硬币种选择结果为j-coints[i-1]的
 * 其实可以有上面的递推关系式推导而来：
 * 已知有：dp[i][j] = dp[i-1][j] + dp[i-1][j-coins[i-1]] + dp[i-1][j-2*coins[i-1]] + ...
 * 则     dp[i][j-coins[i-1]] = dp[i-1][j-coins[i-1]] + dp[i-1][j-coins[i-1]-coins[i-1]] + dp[i-1][j-coins[i-1]-2*coins[i-1]] + ...
 * 带入得：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
*/

/**方法3
 * 进阶2:状态压缩
 * 
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int change(int amount, vector<int>& coins){
        // 方法1：
        int n = coins.size();
        vector<vector<int> > dp(n+1, vector<int>(amount+1,0));
        // 初始化:
        for(int i = 0; i<=n; i++){
            // 前i种硬币组成金额为0的组合数为1
            dp[i][0] = 1;
        }
        // 递推：
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                for(int k=0; k*coins[i-1]<=j; k++){
                    dp[i][j] += dp[i-1][j-k*coins[i-1]];
                }
            }
        }

        return dp[n][amount];
    }

    int change2(int amount, vector<int>& coins){
        //方法2:
        int n = coins.size();
        vector<vector<int> > dp(n+1, vector<int>(amount+1,0));
        // 初始化:
        for(int i = 0; i<=n; i++){
            // 前i种硬币组成金额为0的组合数为1
            dp[i][0] = 1;
        }
        // 递推：
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=amount; j++){
                if(j>=coins[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }

    int change3(int amount, vector<int>& coins){
        // 方法3:
        int n = coins.size();
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        // for(int i = 1; i<=n; i++){
        //     for(int j = 1; j<=amount; j++){
        //         //这里需要从前往后，为什么？
        //         //因为根据方法2得到的递推关系式：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
        //         //当写入dp[j]时需要用的变量是旧的dp[j]和新的dp[j-coins[i-1]]
        //         //注意需要的并不是dp[i-1][j-coins[i-1]]而是dp[i][j-coins[i-1]],即在当前i的循环下更新了的值
        //         //所以此值应该在j循环到j之前产生，即需要从前往后
        //         if(j>=coins[i-1]) dp[j] += dp[j-coins[i-1]];
        //     }
        // }
        // return dp[amount];

        // *** 更进一步，观察发现，如果当j<coins[i-1]的时候，dp[j]不更新，所以为了进一步减少循环次数，可以j直接从coins[i-1]开始，即：
        for(int i = 1; i<=n; i++){
            for(int j = coins[i-1]; j<=amount; j++){
                dp[j] += dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
};

int main(){
    vector<int> coins;
    int n;
    cout << "请问你有几种硬币" <<endl;
    cin >> n;
    cout << "请输入你的硬币面额分别是多少：" <<endl;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        coins.push_back(k);
    }
    int amount;
    cout << "请问你期望得到的金额是多少：" <<endl;
    cin >> amount;

    Solution s;
    cout << "一共有：" << s.change(amount,coins) << " 种组合方法。" << endl;
    cout << "一共有：" << s.change2(amount,coins) << " 种组合方法。" << endl;
    cout << "一共有：" << s.change3(amount,coins) << " 种组合方法。" << endl;

    return 0;
}