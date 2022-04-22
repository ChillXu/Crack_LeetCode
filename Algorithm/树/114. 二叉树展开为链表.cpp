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
//先序遍历存储TreeNode指针，再重新构造
//
class Solution {
public:
    void preOrder(TreeNode* root, vector<TreeNode*> &list){
        if(!root){
            return;
        }
        list.push_back(root);
        preOrder(root->left,list);
        preOrder(root->right,list);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> list;
        preOrder(root,list);
        int n=list.size();
        for(int i=1;i<n;++i){
            TreeNode *prev=list[i-1],*cur=list[i];
            prev->left=nullptr;
            prev->right=cur;
        }
    }
};
