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

//
//堆栈中序遍历
//
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        //stk.push(root);        //会push两个根节点进去
        long long preval=(long long)INT_MIN-1; //val最小值是INT_MIN，若输入为INT_MIN（即[-2147483648]），不减1会输出false，而实际单个根结点应为true，所以需要减1
        while(!stk.empty() || root!=nullptr){   //当左子树节点全部出栈后，堆栈为空，但是此时右指针不为nullptr，需要继续遍历右子树！！！（不需要再在一开始判断根节点为空的情况了）
            while(root!=nullptr){
                stk.push(root);
                root=root->left;
            }
            root=stk.top();
            stk.pop();
            if(root->val<=preval){
                return false;
            }
            preval=root->val;
            root=root->right;
        }
        return true;
    }
};

//
//递归
//
