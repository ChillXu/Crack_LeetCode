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
 //dfs 不共享内存
 //
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr){
            return nullptr;
        }
        int a=root1?root1->val:0;
        int b=root2?root2->val:0;
        TreeNode *merged=new TreeNode(a+b);
        merged->left=mergeTrees(root1?root1->left:nullptr,root2?root2->left:nullptr);   // 保证root其中一个为nullprt时，另一个能继续建完其深层的树
        merged->right=mergeTrees(root1?root1->right:nullptr,root2?root2->right:nullptr);
        return merged;
    }
};


//
//dfs 共享原树内存
//
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }
        TreeNode *merged=new TreeNode(root1->val+root2->val);
        merged->left=mergeTrees(root1->left,root2->left);
        merged->right=mergeTrees(root1->right,root2->right);
        return merged;
    }
};
