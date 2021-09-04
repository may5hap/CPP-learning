/**题目：
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 你可以按 任何顺序 返回答案。
*/

/**分析：
 * 从n个数中选k个数进行组合，【1，2】和【2，1】是一样的
 * dfs+回溯，三要素：
 * 1、base case（终止条件）
 * 2、路径（已选元素）
 * 3、可选列表（可选元素）
 * 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > ret;
    vector<bool> visited;
    vector<vector<int> > combine(int n, int k){
        if(n<=0 || k<=0) return ret;
        visited = vector<bool>(n+1,false);
        vector<int> selected;
        dfs(selected,1,k,n);
        return ret;
    }
    void dfs(vector<int>& selected, int start, int k, int n){
        // selected表示当前已选的元素，start表示下一个元素可以从start开始选，不能比start小，这是因为[1,2]和[2,1]是一样的，以免造成重复
        // 终止条件：当当前路径长度（已选元素个数）等于k时
        if(selected.size()==k){
            ret.push_back(selected);
            return;
        }
        // 循环列表：可选列表，可选元素
        for(int i = start; i<=n; i++){
            // 在参数中传来一个start比较好，这样解决了重复的问题，如果题目变通为可以重复，那么把这个参数去掉即可
            // 如果是全排列，只需要删掉start参数，然后把k改成n即可
            // 排列问题是有序的，而组合是无序的
            if(!visited[i]){
                // 只有当没有 访问过的元素才能被加入
                visited[i]=true;
                selected.push_back(i);
                // 继续深度遍历
                dfs(selected, i+1, k, n);
                //回溯
                selected.pop_back();
                visited[i]=false;
            }
        }
    }
};

int main(){
    int n, k;
    cout << "请输入整数n和k：" << endl;
    cin >> n >> k;
    Solution s;
    cout << "所有组合为：" << endl;
    vector<vector<int> > ans = s.combine(n,k);
    cout << ans.size() << ans[0].size() << endl;
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}