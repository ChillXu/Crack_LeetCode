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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root!=nullptr){
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }
};


//
//
//
class Solution {
public:
    int reverse_postorder(TreeNode* root, int tmp){
        if(!root) return tmp;                               // tmp为该节点右边的所有节点的值的总和（所有比该节点大的节点）
        root->val += reverse_postorder(root->right,tmp);
        return reverse_postorder(root->left,root->val);     // 将累加后的结果传递给左边节点
    }
    TreeNode* convertBST(TreeNode* root) {
        reverse_postorder(root,0);
        return root;
    }
};
