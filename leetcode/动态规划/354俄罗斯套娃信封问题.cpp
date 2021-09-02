/**题目：
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 * 注意：不允许旋转信封。
*/

/**思路：
 * 这是最长上升子序列问题的拓展
 * 如果将信封按照宽度进行排序，则可转换为最长上升子序列问题，具体而言：
 * 将信封按照宽度递增排序，如果宽度相同，则按照高度递减排序，然后只要对高度进行分析，利用最长上升子序列求解即可
 * 为什么宽度相同时高度要递减排序？
 * 首先，宽度相同的信封只能选择一个，如果高度也递增排序，那么问题并没有完全转化成一个最长上升子序列问题
 * 因为如果是完全转化成与宽度无关的一个最长上升子序列问题，那么有可能选择宽度相同的多个信封使高度满足递增
 * 也就是说有两种方法：
 * 1、将信封按照宽度递增排序，如果宽度相同，则按照高度递减排序
 * 2、将信封按照宽度递增排序，如果宽度相同，高度随意
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int mostEnvelopes1(vector<vector<int> > & envelopes){
        // 方法1:动态规划+排序方法1
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        int n = envelopes.size();
        vector<int> dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(envelopes[i][1]>envelopes[j][1]) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }

    int mostEnvelopes2(vector<vector<int> > & envelopes){
        // 方法2:动态规划+排序方式2
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0];});
        int n = envelopes.size();
        vector<int> dp(n,1);
        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0]) 
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }

    int mostEnvelopes3(vector<vector<int> > & envelopes){
        // 进阶：二分法 (参考300最长上升子序列的求解)
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        int n = envelopes.size();
        vector<int> height(n);
        for(int i = 0; i<n; i++) height[i] = envelopes[i][1];
        return LIS(height);
    }

    int LIS(vector<int> & data){
        int n = data.size();
        int piles = 0;
        vector<int> small(n);
        for(int i = 0; i<n; i++){
            int num = data[i];
            int left = 0, right = piles;
            while(left < right){
                int mid = left + (right - left)/2;
                if(num>small[mid]) left = mid+1;
                else right = mid;
            }
            if(left == piles) piles++;
            small[left] = num;
        }
        return piles;
    }

};

int main(){
    vector<vector<int> > envelopes;
    int n, tmp;
    vector<int> arr;
    cout << "你有多少个信封？" <<endl;
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "请输入第" << i+1 << " 个信封尺寸：" <<endl;
        while(cin >> tmp){
            arr.push_back(tmp);
            if(cin.get()=='\n'){
                envelopes.push_back(arr);
                arr.clear();
                break;
            }
        }
    }
    Solution s;
    cout << "最多有:" << s.mostEnvelopes1(envelopes) << " 个信封能组成俄罗斯套娃信封" <<endl;
    cout << "最多有:" << s.mostEnvelopes2(envelopes) << " 个信封能组成俄罗斯套娃信封" <<endl;
    cout << "最多有:" << s.mostEnvelopes3(envelopes) << " 个信封能组成俄罗斯套娃信封" <<endl;
    return 0;
}