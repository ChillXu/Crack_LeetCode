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
//dfs
//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){              // 先序遍历
            return root;
        }                                                     // 越过叶节点、root等于p或q返回
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left==nullptr && right==nullptr) return nullptr;   // 左右子树都没有p或q
        if(left==nullptr) return right;                       // 左子树空，右子树不为空，右子树存在p或q
        if(right==nullptr) return left;                       // 左子树存在p或q（一直向上返回，如果最终合并的右子树为nullptr，则说明另一个p或q还在该左子树的下方）
        return root;                                          // 左右子树均不为空，则root就是最近公共祖先
    }
};
