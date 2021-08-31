#include<iostream>
#include<vector>

using namespace std;

/*  *
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/

/*  * 解法：
    * 假设给其中的某一部分元素加上“+”，另一部分加上“-”，符号为“+“的元素的和为SUM(A)，符号为“-”的元素的和为SUM(B)
    * 那么有关系式： SUM(A) - SUM(B) = target 且 SUM(A) + SUM(B) = SUM(nums)
    * 所以有SUM(A) = (target+SUM(nums))/2 , SUM(B) = (SUM(nums)-target)/2
    * 所以问题转换成在数组nums中，找到和为SUM(A)或者SUM(B)的子序列的个数，即0-1背包问题
    * 在nums数组中，元素有两种选择，要么被选，要么不被选，被选元素的和正好为SUM(A)或者SUM(B)
    * 由于SUM(B) 比 SUM(A)小，所以选择SUM(B)以减少动态规划的空间资源消耗
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int & x: nums) sum += x;
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0){
            return 0;
        }
        // 问题转化成：在nums中找子集的个数，满足条件：
        // 子集和为t
        // 0-1 背包
        int neg = diff/2;
        //int neg = diff/2+target;  //这样的空间消耗会稍微更高一点
        vector<vector<int> > dp(n+1, vector<int>(neg+1));
        dp[0][0] = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=neg; j++){
                if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][neg];
    }
};

int main(){
    // vector<int> nums;
    // int n;
    // cout<< "输入数组长度（正整数）：" <<endl;
    // cin >> n;
    // cout << "请输入数组的值（空格隔开）：" <<endl;
    // for(int i =0; i<n; i++){
    //     int k;
    //     cin >> k;
    //     nums.push_back(k);
    // }
    // int target;
    // cout<< "输入你想得到的结果：" <<endl;
    // cin >> target;
    vector<int> nums = vector<int>(5,1);
    int target = 3;
    Solution s;
    cout << s.findTargetSumWays(nums,target) << endl;
    return 0;
}