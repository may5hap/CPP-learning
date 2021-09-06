/**题目大意：
 * 二叉平衡树的判断，填空题
*/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isBalance(TreeNode* root){
        if(root==nullptr) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        int diff = left - right;
        if(diff < -1 || diff > 1) return false;
        return isBalance(root->right) && isBalance(root->left);
    }
    int depth(TreeNode * root){
        if(root==nullptr) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return left>right? left+1 : right+1;
    }
};


 