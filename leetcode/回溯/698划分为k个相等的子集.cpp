/**题目：
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 * 如：输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
*/

/**分析：
 * 划分成k个总和相等的子集，则每个子集的和为target = sum(nums)/k
 * 每个数字都有可能放入k个子集中的某一个（只要符合条件：当前子集的和小于target）
 * 以此判断每一个数字适合放在哪个子集
 * 如果放入某个子集之后，发现后续不能成功划分，则需要将此数换一个子集，即回溯
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool canSplit(vector<int>& nums, int k){
        int n = nums.size();
        int target = 0;
        for(auto x: nums) target+=x;
        if(target%k!=0) return false;
        target /= k;
        vector<int> subsets(k);
        return backtrace(nums,0,subsets,target);
    }

    bool backtrace(vector<int>& nums, int idx, vector<int>& subsets, const int target){
        if(idx==nums.size()){
            for(auto x:subsets){
                if(x>target) return false;
            }
            return true;
        }
        for(auto x:subsets){
            // 为了尽可能多的命中此if，可先将nums从大到小排序，因为idx从0开始，所以尽可能将大数先分配，来减少复杂度
            if(x+nums[idx]>target) continue;        
            x+=nums[idx];
            if(backtrace(nums,idx+1,subsets,target)) return true;
            x-=nums[idx];
        }
        return false;
    }
};

int main(){
    vector<int> nums;
    int k;
    cout << "请输入你的数组：" << endl;
    while(cin>>k){
        nums.push_back(k);
        if(cin.get()=='\n') break;
    }
    cout << "请输入你想分成多少份：" << endl;
    cin >> k;
    Solution s;
    cout << "能否分割成功：" << s.canSplit(nums,k) << endl;
    return 0;
}