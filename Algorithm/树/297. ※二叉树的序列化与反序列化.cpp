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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "null";
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;		// 先序遍历
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> data_list=split_str(data);
        TreeNode *root=buildTree(data_list);
        return root;
    }

    list<string> split_str(string& data) {
        data=data + ",";  		// 由于serialize的写法字符串最后没有 ',' 需要添加一个符号才能读取到最后一个节点值！！！
        list<string> data_list;
        int start=0,end=0;
        for(char c:data){
            if(c==','){
                data_list.push_back(data.substr(start,end-start));
                start=end+1;
            }
            ++end;
        }
        return data_list;
    }

    TreeNode* buildTree(list<string>& data_list){
        string node=data_list.front();
        data_list.pop_front();
        if(node=="null") return nullptr;
        TreeNode *root=new TreeNode(stoi(node));
        root->left=buildTree(data_list);	// data_list一直在pop，列表还是有变化的
        root->right=buildTree(data_list);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
