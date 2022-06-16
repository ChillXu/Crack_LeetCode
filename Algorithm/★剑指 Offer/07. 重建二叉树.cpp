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
//题目：根据 前序遍历&中序遍历 的结果，构建二叉树并返回其根节点。
//preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//[3,9,20,null,null,15,7]
//
//前序遍历获得根节点，通过中序遍历的结果将二叉树划分为左子树和右子树
//对左子树和右子树进行递归构建
//
class Solution {
public:
    unordered_map<int,int> index;

    TreeNode* buildNodes(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right){
        if(pre_left>pre_right){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[pre_left]);  //前序遍历的节点即为当前根节点
        int in_root=index[preorder[pre_left]];    //找到该根节点在中序遍历中的索引
        int size_left_subtree=in_root-in_left;    //计算左子树的大小
        root->left=buildNodes(preorder, inorder, pre_left+1, pre_left+size_left_subtree, in_left, in_root-1);  //递归构建左右子树
        root->right=buildNodes(preorder, inorder, pre_left+size_left_subtree+1, pre_right, in_root+1, in_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;++i){    //用哈希表存储中序遍历的索引，方便直接获取节点对应的索引
            index[inorder[i]]=i;
        }
        return buildNodes(preorder,inorder,0,n-1,0,n-1);
    }
};
