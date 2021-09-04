/**题目：
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。
 * 你可以 按任意顺序 返回答案。
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

/**分析：
 * 按照77组合中的说法，只需要稍加修改即可
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > ans;
    vector<bool> visited;
    vector<vector<int> > permute(vector<int> & nums){
        int n = nums.size();
        visited = vector<bool>(n,false);
        vector<int> selected;
        dfs(n,nums,selected);
        return ans;
    }

    void dfs(int n, vector<int>& nums, vector<int>& selected){
        // 终止条件：selected的长度等于nums的长度，即所有元素都选了一遍
        if(n==selected.size()){
            ans.push_back(selected);
            return;
        }
        // 循环列表：可选列表
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                // 选择下标为i的元素
                visited[i]=true;
                selected.push_back(nums[i]);
                // 继续深度遍历
                dfs(n,nums,selected);
                // 回溯
                selected.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main(){
    vector<int> nums;
    cout << "请输入你的数组：" << endl;
    int tmp;
    while(cin>>tmp){
        nums.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    Solution s;
    cout << "全排列：" << endl;
    vector<vector<int> > ans = s.permute(nums);
    cout << ans.size() << ans[0].size() << endl;
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}