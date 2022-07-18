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
//递归（DFS）
//
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return check(root->left,root->right);
    }

    bool check(TreeNode* l, TreeNode* r){
        if(l==nullptr && r==nullptr){
            return true;
        }
        if(l==nullptr || r==nullptr || l->val!=r->val){
            return false;
        }
        return check(l->left,r->right) && check(l->right,r->left);
    }
};

//
//利用队列，按层入队出队（BFS）
//
