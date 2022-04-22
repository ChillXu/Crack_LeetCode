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
//BFS
//利用队列先进先出FIFO的特点，当前结点访问后，将其左右子结点先后入队
//
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root){return res;}       //！！！！
        q.push(root);
        int level=0;
        while(!q.empty()){
            int curLevelSize=q.size();
            res.push_back(vector<int>());
            for(int i=0;i<curLevelSize;++i){
                TreeNode *node=q.front();
                res[level].push_back(node->val);  //root为nullptr时，node->val出错！
                if(node->left){                   //res.back().push_back(node->val) 则不需要level记录
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
            level++;
        }
        return res;
    }
};

//
//DFS
//
class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>> &res, int level){
        if(!root){
            return;
        }
        if(level>=res.size()){
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
};
