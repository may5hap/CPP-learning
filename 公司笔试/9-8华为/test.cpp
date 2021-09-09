#include<iostream>
#include<vector>

using namespace std;
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

int getSubSum(TreeNode* root){
    if(root==nullptr) return 0;
    return getSubSum(root->left) + getSubSum(root->right) + root->val;
}

int getResult(vector<TreeNode*> & tree, int n, int sum){
    int ans = 0;
    vector<int> subSum(n);
    for(int i = 0; i<n; i++){
        subSum[i] = getSubSum(tree[i]);
        //cout << subSum[i]<< endl;
        ans = max(ans,abs(subSum[i]-sum));
    }
    return ans;
}

int main()
{
    // 实际上就是将数分成两棵树，两棵树的节点和的绝对值最大
    // 先求得总和sum，所以也就是寻找以某一个节点为根的子树，使得子树的和subsum与sum的绝对值最大
    int n;
    vector<TreeNode*> node;
    cin >> n;
    int tmp;
    int sum;
    TreeNode* cur = nullptr;
    while(cin >> tmp){
        cur =  new TreeNode(tmp);
        node.push_back(cur);
        sum += tmp;
    }
    //string ab;
    int a,b;
    while(cin>>a>>b){
        // ？？？？
        //cout << ab << endl;
        // cout << a << b << endl;
        if(node[a]->left!=nullptr){
            node[a]->right = node[b];
        }
        else{
            node[a]->left = node[b];
            //cout << "..." << endl;
        }
    }
    // cout << (node[0]->left==nullptr) << endl;
    int ans = getResult(node,n,sum);
    cout << ans << endl;
    return 0;
}
