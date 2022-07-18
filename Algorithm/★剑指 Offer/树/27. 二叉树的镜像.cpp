/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//
//递归
//
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        TreeNode* left=mirrorTree(root->left);
        TreeNode* right=mirrorTree(root->right);
        root->left=right;      // right、left为新节点，否则需要借助第三个节点交换
        root->right=left;
        return root;
    }
};
