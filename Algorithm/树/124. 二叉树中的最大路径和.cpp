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
//
//
class Solution {
public:
    int ans=INT_MIN;
    int dfs(TreeNode* root){        // 返回以root为根节点的子树对外能提供的最大路径和
        if(!root) return 0;
        int l=dfs(root->left), r=dfs(root->right);    // 左右子树提供的最大路径和
        int inSum=root->val + l + r;                  // 计算以root为根的子树内部最大路径和
        ans=max(ans,inSum);
        int outSum=root->val + max(0,max(l,r));       // 一条路径不能两头都走，以root为根节点的子树对外提供的最大路径和
        return max(0,outSum);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
