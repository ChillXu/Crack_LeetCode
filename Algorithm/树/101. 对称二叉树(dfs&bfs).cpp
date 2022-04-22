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
//递归（DFS）
//
class Solution {
public:
    bool check(TreeNode* l, TreeNode* r){
        if(l==nullptr && r==nullptr){       
            return true;
        }
        if(l==nullptr || r==nullptr || l->val!=r->val){   //只有一个为空，左右子树不等，或者值不等，返回false
            return false;
        }
        return check(l->left,r->right) && check(l->right,r->left);  //比较 左子树的左结点和右子树的右结点 & 左子树的右结点和右子树的左结点！！！
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return check(root->left,root->right);
    }
};

//
//BFS
//
