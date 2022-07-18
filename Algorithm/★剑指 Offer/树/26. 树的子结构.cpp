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
//三种情况：   1.B子结构起点为A的根节点；
//            2.B子结构起点隐藏在A的左子树中；
//            3.B子结构起点隐藏在A的右子树中。
//
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr || A==nullptr){    //空树不是任意一个树的子结构，A为空时已无法含有B子结构
            return false;
        }
        return recur(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    bool recur(TreeNode* A, TreeNode* B){     //判断B是否为A的子结构，其中B子结构的起点为A的根节点
        if(B==nullptr){
            return true;
        }
        if(A==nullptr || A->val!=B->val){
            return false;
        }
        return recur(A->left,B->left)&&recur(A->right,B->right);
    }
};
