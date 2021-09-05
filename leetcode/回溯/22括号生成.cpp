/**题目：
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 有效括号组合需满足：左括号必须以正确的顺序闭合。
*/

/**分析：
 * 生成n对有效的括号，其实就是在2n个位置上防止'('和')'，但需要满足有效的条件
 * 一个有效的括号字符串应该满足：
 * 1、左右括号个数相等
 * 2、从第一个位置开始的任意子串中，左括号的个数比右括号的个数多
 * 上述条件也就是dfs终结的条件
 * 路径就是已选择的字符串
 * 可选列表就是两个：左括号和右括号
 * 
 * 由于是生成所有的可能括号字符串，故dfs返回void，用一个全局变量保存可能的结果
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
public:
    vector<string> ans;
    vector<string> generateBrackets(int n){
        string selected;
        dfs(0, 0, n, selected);
        return ans;
    }

    void dfs(int lv, int rv, int n, string& selected){
        if(lv==n && rv==n){
            // 如果已选的做括号个数和右括号个数都等于n，则表明当前所组成的括号字符串是一个解，上述终止条件1
            ans.push_back(selected);
            return;
        }
        if(lv>n || lv<rv){
            // 即上面所述的终止条件2，这里再补上条件lv<n，即左括号的个数小于n，降低复杂度
            return;
        }

        // 可能的选择：
        // 1、选择左括号：
        selected.push_back('(');
        // dfs
        dfs(lv+1, rv, n, selected);
        // 回溯
        selected.pop_back();

        // 2、选择右括号:
        selected.push_back(')');
        // dfs
        dfs(lv, rv+1, n, selected);
        // 回溯
        selected.pop_back();

    }
};

int main(){
    int n;
    cout << "请输入你的括号对数：" << endl;
    cin >> n;
    Solution s;
    vector<string> ans = s.generateBrackets(n);
    for(int i = 0; i< ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}