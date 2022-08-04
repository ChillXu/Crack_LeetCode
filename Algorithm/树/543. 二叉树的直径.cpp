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
//错误想法：直径为左子树和右子树的最大深度之和，然而作为直径的最长路径可能不经过根节点，所以树中的每一个节点都有可能是路径的根节点
//
class Solution {
public:
    int dfs(TreeNode* root){      // 求深度
        if(!root) return 0;
        return 1+max(dfs(root->left),dfs(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=dfs(root->left)+dfs(root->right);
        diameter=max(diameter,diameterOfBinaryTree(root->left));
        diameter=max(diameter,diameterOfBinaryTree(root->right));
        return diameter;
    }
};


//
//maxlen在递归中计算
//
class Solution {
public:
    int dfs(TreeNode* root, int& maxlen){
        if(!root) return 0;
        int l=dfs(root->left,maxlen);
        int r=dfs(root->right,maxlen);
        maxlen=max(maxlen,l+r);   // 保存当前最长路径
        return 1+max(l,r);        // 返回当前树的深度
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxlen=0;
        dfs(root,maxlen);
        return maxlen;
    }
};
