#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void readtree(TreeNode* root){
    //层次遍历
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        cout<<node->val<< "  ";
        if(node->left!=nullptr) q.push(node->left);
        if(node->right!=nullptr) q.push(node->right);
    }
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return vector<TreeNode* >();
        return build(1, n);
    }
    vector<TreeNode*> build(int l, int r){
        vector<TreeNode*> ret;
        if(l>r){
            ret.push_back(nullptr);
            return ret;
        }
        for(int i = l; i<=r; i++){
            vector<TreeNode*> lefttrees = build(l, i-1);
            vector<TreeNode*> righttrees = build(i+1, r);
            for(TreeNode* le : lefttrees){
                for(TreeNode* ri : righttrees){
                    TreeNode* root = new TreeNode(i);
                    root->right = ri;
                    root->left = le;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<TreeNode*> ans = s.generateTrees(n);
    vector<TreeNode*>::iterator it = ans.begin();
    while(it++!=ans.end()){
        readtree(*it);
    }
    return 0;
}