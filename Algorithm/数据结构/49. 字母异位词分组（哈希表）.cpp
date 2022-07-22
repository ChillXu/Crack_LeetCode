//
//对每个字符串进行排序，排序之后的字符串作为哈希表的键值
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        for(auto str:strs){
            string tmp=str;
            sort(tmp.begin(),tmp.end());
            hash[tmp].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it=hash.begin();it!=hash.end();++it){    // 哈希表遍历方法！！！
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
