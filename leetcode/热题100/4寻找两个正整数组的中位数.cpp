/**
 * @file 4寻找两个正整数组的中位数.cpp
 * @author whao 
 * @brief 
 * @version 0.1
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 请你找出并返回这两个正序数组的 中位数 。
 * 
 */

/**
 * 最简单的做法：
 * 合并两个有序数组，查找中位数
 * 复杂度：O(m+n)
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int i = 0, j = 0;
        while(i != nums1.size() && j != nums2.size()){
            if(nums1[i]<nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        if(i == nums1.size()){
            for(int k = j; k<nums2.size(); k++) nums3.push_back(nums2[k]);
        }
        if(j == nums2.size()){
            for(int k = i; k<nums1.size(); k++) nums3.push_back(nums1[k]);
        }
        int mid = (nums3.size()-1)>>1;
        if(nums3.size()%2==1) {
            return nums3[mid];
        }
        else{
            return (nums3[mid]+nums3[mid+1])/2.0;
        }


    }
};

int main(){
    cout << "输入你的两个有序数组：" << endl;
    vector<int> v1;
    vector<int> v2;
    int tmp;
    while(cin>>tmp){
        v1.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    while (cin>>tmp)
    {
        v2.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    Solution s;
    int ans = s.findMedianSortedArrays(v1,v2);
    cout << ans << endl;

    return 0;
}