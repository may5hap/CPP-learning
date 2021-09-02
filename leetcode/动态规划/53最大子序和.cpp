/**题目：
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/

/**分析：
 * 典型的动态规划题目：还是两种状态设计的思路：
 * 1、dp[i]表示0...i 中连续子数组的最大和
 * 2、dp[i]表示以第i个元素结尾的连续子数组的最大和
 * 那么选择哪一种呢？分析：
 * 如果选择第一种，当已知dp[0],dp[1],...dp[i-1],如何推导出dp[i]?
 * 推导不出来，因为无法判断当前最大和的连续子数组是否和i也能构成连续的关系
 * 故选择第二种，因为第二种的定义中就包含了条件是以i结尾的连续子数组
 * 所以，递推关系： dp[i] = max(dp[i-1]+nums[i],nums[i])
 * 即：当已知dp[0],dp[1],...dp[i-1]，如果选择第i个元素，那么有dp[i]=dp[i-1]+nums[i],
 * 如果不选择第i个元素，那么有dp[i] = nums[i],即以i开始和以i结尾的子数组的和
 * 所以dp[i]即为两者的最大值
 * 所以最后要求的整个数组的连续子数组的最大和即dp[0]...dp[n]的最大值
*/

/**进阶：
 * 状态压缩，观察上面的推导发现： dp[i] = max(dp[i-1]+nums[i],nums[i]),即dp[i]至于dp[i-1]和nums[i]有关
 * 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int maxSum(vector<int> & nums){
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1; i<n; i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }

    int maxSum2(vector<int> & nums){
        int n = nums.size();
        int pre=nums[0], cur=0, ans = nums[0];
        for(int i = 1; i<n; i++){
            cur = nums[i];
            if(pre>0) cur += pre;
            pre = cur;
            ans = max(ans,cur); 
        }
        return ans;
    }
};

int main(){
    vector<int> nums;
    cout << "请输入你的数组：" <<endl;
    int tmp;
    while(cin>>tmp){
        nums.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    Solution s;
    cout << "你输入数组的连续子数组的最大和为：" << s.maxSum(nums) <<endl;
    cout << "你输入数组的连续子数组的最大和为：" << s.maxSum2(nums) <<endl;
    return 0;
}