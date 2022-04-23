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
//递归
//
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &res){
        if(!root){
            return;
        }
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

//
//迭代堆栈实现
//
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (!stk.empty()|| root!=nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

//Morris 遍历算法是另一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 O(1)。
/*
Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 x）：
1.如果 x 无左孩子，先将 x 的值加入答案数组，再访问 x 的右孩子，即 x = x.right。
2.如果 x 有左孩子，则找到 x 左子树上最右的节点（即左子树中序遍历的最后一个节点，xx 在中序遍历中的前驱节点），我们记为 predecessor。根据 predecessor 的右孩子是否为空，进行如下操作。
      如果 predecessor 的右孩子为空，则将其右孩子指向 x，然后访问 x 的左孩子，即 x = x.left。
      如果 predecessor 的右孩子不为空，则此时其右孩子指向 x，说明我们已经遍历完 x 的左子树，我们将 predecessor 的右孩子置空，将 x 的值加入答案数组，然后访问 x 的右孩子，即 x = x.right。
3.重复上述操作，直至访问完整棵树。
*/
