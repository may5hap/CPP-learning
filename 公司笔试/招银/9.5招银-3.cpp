/**题意：
 * 字符串由数字组成，将字符串划分为若干子串是的每个子串对应的数字在1-16之间，如
 * 1013可以分成10 13 或者 10 1 3， 有两种分法
 * 求给定字符串有多少种分法
*/

/**动态规划，分析如下：
 * dp[i]表示输入的字符串从0-i的子串的分法
 * 如果nums[i]==0 ，那么dp[i]=dp[i-2]，因为0不能单独作为一个子串，所以0必然跟前面的一个数字合并，且前面一个数字必然为1（根据题意）
 * 如果nums[i]不等于0，那么分情况：
 * 1、nums[i]>=7,则无法跟前面的数字组合，只能自成一组，此时dp[i] = dp[i-1]
 * 2、nums[i]在[1,6]之间，此时还要再分情况：
 *      a：nums[i-1] == 1:此时可合并，也可不合并，如果合并则有dp[i-2],如果不合并,则有dp[i-1]种，所以总的有dp[i]=dp[i-1]+dp[i-2]
 *      b: nums[i-1] != 1:此时不可合并，所以dp[i] = dp[i-1]
 * 初始化：
 * dp[0] = 1(nums[0]!=0,否则不满足题意，或者直接先把开始的0删除)
 * dp[1]需要分情况：
 * 1、如果nums[1]==0,则必须合并，dp[1] = 1
 * 2、如果nums[1]>=7，则不能合并，dp[1] = 1
 * 3、nums[1]在[1,6]之间，此时还要再分情况：
 *      a:nums[0] == 1,此时dp[1] = 2
 *      b:nums[0] != 1,此时dp[1] = 1
*/

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> & nums, int n){
    vector<int> dp(n,0);
    dp[0] = 1;
    if(nums[1]>=7 || nums[1]==0) dp[1] = 1;
    else if(nums[0]==1) dp[1] = 2;
    else dp[1] = 1;
    for(int i = 2; i<n; i++){
        if(nums[i]==0) dp[i] = dp[i-2];
        else if(nums[i]>=7) dp[i] = dp[i-1];
        else if(nums[i-1]==1) dp[i] = dp[i-1]+dp[i-2];
        else dp[i] = dp[i-1];
    }
    return dp[n-1];
}

int main(){
    int n;
    vector<int> nums(n,0);
    cout << "你的字符串长度为：" << endl;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }
    // 去除开始的0
    // int i = 0;
    // while(nums[i]==0 && i<n){
    //     nums.erase(nums.begin()+i);
    //     i++;
    // }
    int ans = solve(nums, n);
    cout << ans << endl;
    return 0;
}