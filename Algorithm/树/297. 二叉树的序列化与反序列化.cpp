/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "X";
        string left=serialize(root->left);
        string right=serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> data_list=split_str(data);
        TreeNode *root=buildTree(data_list);
        return root;
    }

    // list<string> split_str(string& data) {
    //     list<string> data_list;
    //     int start=0,end=-1;
    //     for(char c:data){
    //         ++end;
    //         if(c==','){
    //             data_list.push_back(data.substr(start,end-start));
    //             start=end+1;
    //         }
    //     }
    //     return data_list;
    // }
    list<string> split_str(string& str)
	{
		list<string> res;
		for (int lastpos = -1, pos = 0; pos < str.length(); pos++)
		{
			if (str[pos] == ',')
			{
				res.push_back(str.substr(++lastpos, pos - lastpos));
				lastpos = pos;
			}
		}
		return res;
	}

    TreeNode* buildTree(list<string>& data_list){
        string node=data_list.front();
        data_list.pop_front();
        if(node=="X") return nullptr;
        TreeNode *root=new TreeNode(stoi(node));
        root->left=buildTree(data_list);
        root->right=buildTree(data_list);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
