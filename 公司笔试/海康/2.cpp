#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > ans;
    vector<bool> visited;
    void backtrack(vector<int>& output, vector<int>& nums, int m){
        if (output.size() == m) {
            ans.emplace_back(output);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 动态维护数组
            if(!visited[i]){
                visited[i] = true;
                output.push_back(nums[i]);
                // 继续递归填下一个数
                backtrack(output, nums, m);
                // 撤销操作
                output.pop_back();
                visited[i] = false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums, int m) {
        vector<int> path;
        visited = vector<bool>(nums.size(),false);
        backtrack(path, nums, m);
        return ans;
    }
};

int main(){
    string input;
    cin >> input;
    // [1,2,3],2
    size_t lastsep = input.find_last_of(',');
    int m = atoi(input.substr(lastsep+1).c_str());
    size_t firstbrk = 0;
    size_t lastbrk = input.find_last_of(']');
    vector<int> nums;
    string subinp = input.substr(firstbrk+1, lastbrk);
    size_t pos = subinp.find(',');
    while(pos!=string::npos){
        nums.push_back(atoi(subinp.substr(0,pos).c_str()));
        subinp = subinp.substr(pos+1);
        pos = subinp.find(',');
    }
    nums.push_back(atoi(subinp.c_str()));
    sort(nums.begin(),nums.end());
    Solution s;
    vector<vector<int> > ans = s.permute(nums, m);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}