/**
 * @file 3.cpp
 * @author whao
 * @brief 
 * @version 0.1
 * @date 2021-09-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

/**
 * @brief 求表达式的值，表达式中有x表示乘法，+表示加法，@表示：a@b = a|(a+b)
 * 如： 10+2@1x2 =  10 + (2 | (2 + 1)) * 2 = 10 + 3 * 2 = 16
 * @return int 
 */

int main(){
    string s;
    cin >> s;
    vector<int> nums;
    vector<char> ops;
    int n = s.size();
    int num = 0;
    for(int i = 0;i < n; i++){
        if(isdigit(s[i])){
            num = num * 10 + s[i] - '0';
        }
        else{
            nums.push_back(num);
            num = 0;
            ops.push_back(s[i]);
        }
    }
    for(int i = 0; i<ops.size(); i++){
        if(ops[i]=='@'){
            int a = nums[i];
            int b = nums[i+1];
            int c = a|(a+b);
            nums[i] = c;
            nums.erase(nums.begin()+i+1);
            ops.erase(ops.begin()+i);
            i = i - 1;
        }
    }
    for(int i = 0; i<ops.size(); i++){
        if(ops[i]=='x'){
            int a = nums[i];
            int b = nums[i+1];
            int c = a*b;
            nums[i] = c;
            nums.erase(nums.begin()+i+1);
            ops.erase(ops.begin()+i);
            i = i - 1;
        }
    }
    int ans = 0;
    for(int x:nums){ans += x;}
    cout << ans << endl;
    return 0;
}

// int main(){
//     string s;
//     cin >> s;
//     stack<int> nums;
//     stack<int> ops;
//     int n = s.size();
//     char preop = '+';
//     int num = 0;
//     for(int i = 0; i<n; i++){
//         char ch = s[i];
//         if(isdigit(ch)){
//             num = num * 10 + ch - '0';
//         }
//         if(i == n - 1 || !isdigit(ch)){
//             if(preop == '@'){
//                 int prenum = nums.top();
//                 nums.pop();
//                 int tmp = prenum | (prenum + num);
//                 nums.push(tmp);
//             }
//             else if(preop == 'x' && ch != '@'){
//                 int prenum = nums.top();
//                 nums.pop();
//                 int tmp = prenum * num;
//                 nums.push(tmp);
//             }
//             else{
//                 nums.push(num);
//             }
//             preop = ch;
//             num = 0;
//         }
//     }
//     int ans = 0;
//     while(!nums.empty()){
//         ans += nums.top();
//         nums.pop();
//     }
//     cout << ans << endl;
//     return 0;
// }