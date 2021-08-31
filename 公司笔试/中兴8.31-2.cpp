#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/* * 题目描述：
    小明家在数轴上的0点，在数轴的其他位置有商店，小明现在需要逛完所有商店，并回到家中
    求最短的路径长度
    */

class Solution{
public:
    int n;
    unordered_map<int, bool> visited;
    int ans;
    vector<vector<int>> paths;
    int getShortest(vector<int> & a){
        n = a.size();
        ans = INT_MAX;
        for(auto x:a){
            vector<int> path;
            dfs(a, 0, x, 0, path);
        }
        return ans;
    }
    void dfs(vector<int> & a, int cur, int next, int sum, vector<int>& path){
        bool isEnd = true;
        for(auto x:a){
            if(!visited[x]){
                isEnd = false;
                break;
            }
        }
        if(isEnd){
            path.push_back(cur);
            return;
        }
        visited[next]=true;
        sum += abs(next-cur);
        cur = next;
        if(ans<sum) return;
        for(auto x:a){
            if(!visited[x]){
                dfs(a,cur,x,sum);
            }
        }
        //ans = sum;
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    Solution s;
    int ans = s.getShortest(a);
    cout << "ans = "<< ans << endl;
    return 0;
}