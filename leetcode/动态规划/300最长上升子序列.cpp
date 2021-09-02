/**题目：
 * 给定一个无序数组，求数组的最长上升子序列长度，如：【10，9，2，5，3，7，101，18】的最长上升子序列长度为4，可以是2 5 7 101
*/

/**分析：
 * 典型的动态规划题
 * 常见的两种状态设计：
 * 1、dp[i][j]表示从i到j的最长上升子序列的长度
 * 2、dp[i][j]表示从i开始，以j结尾的最长上升子序列的长度
 * 由于都是从0开始，二维dp可以压缩成一维dp：dp[j]
 * 上述第一种状态设计并不合适，因为不好推导递推关系，dp[j] = dp[j-1] + 1?不行。 dp[j] = max(dp[j-i],i=1...j) + 1?也不行
 * 因为从i到j的最长上升子序列并不明确其最后一个元素，并不知道当前元素与之前的上升子序列的最后一个元素大小关系
 * 采用第二种状态设计可以解决此问题，因为dp[j]明确了是以第j个元素作为结尾的最长上升子序列的长度
 * 所以递推关系：dp[j] = max(dp[j-i],i=1...j且nums[j-i]<nums[j])
*/

/**进阶：
 * 最长上升子序列问题的时间复杂度为O(N^2)
 * 此题二分法比较难，供参考：
 * 假设 【10，9，2，5，3，7，101，18】
 * 现在将它分成若干堆，每一对的数字按从大到小排序，如果比最后一个数大则放到下一堆：
 *      10      5       7       101
 *      9       3               18
 *      2
 * 最后有多少堆就是最长上升子序列的长度
 * 所以利用二分法为每一个元素去找它应该存放在哪一堆，为此需要一个数组保存了每一堆的最小的数
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int LIS(vector<int> & nums){
        int n = nums.size();
        vector<int> dp(n,1);
        // 初始化,dp[i] = 1 以i结尾的最长上升子序列最少包括自己

        // 递推：
        for(int i = 1; i<n; i++){
            for(int j = i - 1; j>=0; j--){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }

    int LIS2(vector<int> & nums){
        int n = nums.size();
        vector<int> small(n);   // 存放每一堆中的最小数
        int piles = 0;          // 堆数
        for(int i = 0; i<n; i++){
            // 对于数组中的每一个数，去找它应该存放在第几堆
            int left = 0, right = piles;
            int num = nums[i];  //当前的数字
            // 二分:
            while(left<right){
                int mid = left + (right - left)/2;
                if(num>small[mid]) left = mid + 1;
                else right = mid;
            }
            if(left==piles) piles++;//如果left==piles，说明所有堆的最小值都小于num，所以需要新建一堆
            small[left] = num;      // 最后要放到第left堆
        }
        return piles;
    }

};

int main(){
    vector<int> data;
    cout << "请输入你的序列：" <<endl;
    int tmp;
    while(cin>>tmp){
        data.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    // for(int i = 0; i<data.size(); i++){
    //     cout << data[i] << "  ";
    // }
    // cout <<endl;
    Solution s;
    cout << "最长上升子序列长度为：" << s.LIS(data) <<endl;
    cout << "最长上升子序列长度为：" << s.LIS2(data) <<endl;
    return 0;
}
