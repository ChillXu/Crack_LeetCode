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
//dfs
//时间：O(n^2)   空间：O(n)
//
class Solution {
public:
    int rootSum(TreeNode* root, long targetSum){    // 计算以节点root为起点向下，且路径总和满足targetSum的路径数目
        if(!root){                                  // 需要 long 可能中途计算会溢出！
            return 0;
        }
        int ret=0;
        if(root->val==targetSum){
            ret++;
        }
        ret+=rootSum(root->left,targetSum-root->val);
        ret+=rootSum(root->right,targetSum-root->val);
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        int res=rootSum(root,targetSum);        // dfs统计每一个rootSum
        res+=pathSum(root->left,targetSum);     
        res+=pathSum(root->right,targetSum);
        return res;
    }
};


//
//dfs+前缀和
//时间：O(n)   空间：O(n)
//
class Solution {
public:
    int dfs(TreeNode* node, long prefix, int targetSum, unordered_map<long,int>& hash){
        if(!node) return 0;
        int ans=0;
        prefix+=node->val;            // 计算当前前缀和
        ans+=hash[prefix-targetSum];  // 对于同一路径上的两个节点，上面的节点是下面节点的祖先节点，所以其前缀和之差即是这两个节点间的路径和
        hash[prefix]++;               //  [1] 0  不能先更新hash[prefix]
        ans+=dfs(node->left,prefix,targetSum,hash);
        ans+=dfs(node->right,prefix,targetSum,hash);
        hash[prefix]--;               // 状态回溯，因为到另一个分支中，当前前缀和节点不是之后节点的祖先节点
        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long,int> hash;
        hash[0]=1;      // 前缀和为0的路径数目初始化为1
        return dfs(root,0,targetSum,hash);
    }
};
