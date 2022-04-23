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
/*
二叉搜索树  
   1.节点的左子树只包含 小于 当前节点的树
   2.节点的右子树只包含 大于 当前节点的树
   3.所有左子树和右子树自身必须也是二叉搜索树

只需要左节点小于根节点，右节点大于根节点？
*/
//
//中序遍历，若得到的序列是严格单调增的则是有效二叉搜索树
//
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &res){
        if(!root){
            return;
        }
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        vector<int> res;
        inOrder(root,res);
        for(int i=0;i<res.size()-1;++i){
            if(res[i]>=res[i+1]){
                return false;
            }
        }
        return true;
    }
};
