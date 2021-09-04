/**题目：
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

/**这个题也是剑指offer上的一个题
 * 假设nums数组长度为n，那么左右的子集个数为2^n，所以数组长度每增加一个，子集数量加倍
 * 如：【1，2】的所有子集为：【】、【1】、【2】、【1，2】
 * 【1，2，3】的所有子集为：【】、【1】、【2】、【3】、【1，2】、【1，3】、【2，3】，【1，2，3】
 * 观察发现，【1，2，3】的结果包含了【1，2】的子集，且增加了一倍，增加的子集满足：
 * 在【1，2】的所有子集中加入3，由此便可解此问题了
*/

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > ans;
vector<vector<int> > subSet(vector<int>& nums){
    int n = nums.size();
    vector<vector<int> > ret({{}});
    for(int i = 0; i<n; i++){
        int sz = ret.size();
        for(int j = 0; j<sz; j++){
            ret.push_back(ret[j]);
            ret[sz+j].push_back(nums[i]);
        }
    }
    return ret;
}

int main(){
    vector<int> nums;
    int tmp;
    cout << "请输入你的数组：" << endl; 
    while(cin>>tmp){
        nums.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    cout << "所有非空子集为：" << endl;
    ans = subSet(nums);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}