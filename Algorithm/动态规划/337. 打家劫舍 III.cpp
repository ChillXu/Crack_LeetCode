/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//
//用 f(o) 表示选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和；
//用 g(o) 表示不选择 o 节点的情况下，o 节点的子树上被选择的节点的最大权值和。
//
class Solution {
public:
    unordered_map<TreeNode*,int> f,g;

    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node]=node->val+g[node->left]+g[node->right];
        g[node]=max(f[node->left],g[node->left])+max(f[node->right],g[node->right]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};
