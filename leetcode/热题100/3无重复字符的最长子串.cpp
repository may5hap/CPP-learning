/**
 * @file 3无重复字符的最长子串.cpp
 * @author whao 
 * @brief 
 * @version 0.1
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 */

/**
 * 滑动窗口：
 * 用一个map记录当前窗口内的字符个数，当有一个字符个数大于1时，左边界往右移动
 * 
 */

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution{
public:
    int largestSubstr(string s){
        int left = 0, right = 0;
        unordered_map<char,int> mp;
        int n = s.size();
        int ans = 0;
        while(right < n){
            char ch = s[right];
            right++;
            mp[ch]++;
            while(left < right && mp[ch]>1){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};

int main(){
    cout << "输入你的字符串：" << endl;
    string s;
    cin >> s;
    Solution sol;
    int ans = sol.largestSubstr(s);
    cout << ans << endl;
    return 0;
}