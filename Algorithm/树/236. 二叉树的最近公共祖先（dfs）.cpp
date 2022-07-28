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


/*
1. 当 left 和 right 同时为空，说明 root 的左/右子树中都不包含 p,q ，返回 null ；
2. 当 left 和 right 同时不为空，说明 p,q 分列在 root 的异侧（分别在左/右子树），因此 root 为最近公共祖先，返回 root ；
3. 当 left 为空，right 不为空，p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
           p,q 其中一个在 root 的右子树中，此时 right 指向 p（假设为 p ）；
           p,q 两节点都在 root 的右子树中，此时的 right 指向最近公共祖先节点 ；
4. 当 left 不为空， ight 为空，与情况 3. 同理。
*/
