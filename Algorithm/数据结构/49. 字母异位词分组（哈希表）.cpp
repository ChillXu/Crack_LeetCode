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


//
//
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> hash;             // 哈希表记录索引下标
        vector<vector<string>> ans;
        int index=0;
        for(int i=0;i<strs.size();++i){             // 另一种遍历方法
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(hash.count(tmp)){
                ans[hash[tmp]].emplace_back(strs[i]);
            }
            else{
                ans.emplace_back(vector<string>());     // 向ans中插入一个空的string数组，[[]]
                ans[index].emplace_back(strs[i]);
                hash[tmp]=index++;
            }
        }
        return ans;
    }
};
