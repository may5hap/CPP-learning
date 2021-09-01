/*  * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
    * 分析：
    * 这还是一个需要数学的题
    * 分割成两个子集A、B，两个子集的和相等，都等于sum(nums)的一半，所以问题转化：
    * 在数组nums中寻找一个子集，使得其和为数组和的一半
    * 典型的动态规划：
    * dp[i][j]表示在前i个元素中，存在子集的和为j，注意这里的dp[i][j]值为true / false
    * 那么有关系式：
    *       dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]]
    * 理解为：当前是否分割成功，取决于两个方面：（只要有一个成功，即可分割成功）
    *       1、不选取第i个元素，在前i-1个元素的集合中就能分割成功
    *       2、选取第i个元素，判断在前i-1个元素中是否有和为j-nums[i-1]的子集
    * 注意这里要减去nums[i-1]，表示第i个元素的值，因为它在数组中的位置是i-1
    * 
    **** 进阶：
    * 观察这里的状态转移方程，可以压缩dp数组

*/ 

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool canPartition(vector<int>& nums){
        // 1、求得sum(nums)
        int sum = 0;
        for(auto x:nums) sum+=x;
        if(sum%2!=0) return false;  //如果sum不为偶数，而nums中的数都是整数，所以分割失败

        sum /= 2;       // 需要寻找的子集和
        int n = nums.size();

        // // 2、定义dp数组
        // vector<vector<bool> > dp(n+1, vector<bool>(sum+1,false));   

        // // 3、初始化，如果j为0，则不管i为多少，都可分割成功
        // for(int i = 0; i<=n; i++){
        //     dp[i][0] = true;
        // }

        // // 4、本来还应该初始化第一行，即没有元素的情况，如果没有元素，则无论j为多少（0除外），都不能分割成功
        // // 这一步不需要做了，因为初始化已经完成

        // // 5、递推关系
        // for(int i = 1; i<=n; i++){
        //     for(int j = 1; j<=sum; j++){
        //         if(j >= nums[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }

        // return dp[n][sum]; 

        // *** 进阶：
        vector<bool> dp(sum+1,false);
        
        dp[0] = true;
        // 在这里，dp数组相当于是前0个元素能否分割成j=0，1，2，。。。的结果
        // 下面，逐渐增加i，直到n，最后得到的结果即为前n的元素能否分割成j=0，1，2，。。。的结果

        for(int i = 1; i<=n; i++){
            for(int j = sum; j>=0; j--){
                //这里要从sum开始递减，为什么呢？
                //因为，dp[i][j] 与 dp[i-1][j] 和 dp[i-1][j-nums[i-1]]有关，即新的dp[j]与旧的（待覆盖的）dp[j]和dp[j-nums[i-1]]有关
                //如果从前往后，那么前面覆盖了的值会影响后面的结果，如： 待写入的dp[4] 只与 当前已有的dp[4] 和 dp[4-nums[i-1]](有可能是dp[3]或者dp[2]之类的)有关
                //如果从前往后写如，那么 dp[4-nums[i-1]] 可能已经不是旧的dp[4-nums[i-1]]， 而是已经写入的新的dp[4-nums[i-1]]，导致结果错误
                if(j >= nums[i-1]) dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }

        return dp[sum];

    }
};

int main(){
    vector<int> nums;
    cout << "你想输入的数组大小为多少？（整数）：" << endl;
    int n;
    cin >> n;
    cout << "请输入数组的元素：" <<endl;
    for(int i = 0; i<n; i++){
        int k;
        cin >> k;
        nums.push_back(k);
    }

    Solution s;
    cout << "能否分割：" << s.canPartition(nums)<< endl;

    return 0;

}