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
class Solution {
public:
    unordered_map<int,int> index;
    TreeNode* buildNode(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left>pre_right){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[pre_left]);
        int in_root=index[preorder[pre_left]];
        int sizeof_left_tree=in_root-in_left;
        root->left=buildNode(preorder,inorder,pre_left+1,pre_left+sizeof_left_tree,in_left,in_root-1);
        root->right=buildNode(preorder,inorder,pre_left+sizeof_left_tree+1,pre_right,in_root+1,in_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;++i){
            index[inorder[i]]=i;
        }
        return buildNode(preorder,inorder,0,n-1,0,n-1);
    }
};
