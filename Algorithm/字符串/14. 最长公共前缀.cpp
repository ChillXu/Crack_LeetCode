//
//自己写的
//（正常排序后，比较首位两个str的最长公共前缀即可）
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end(),[](const auto& s1, const auto& s2){
            return s1.size()<s2.size();
        });
        for(int i=0;i<strs[0].size();++i){
                for(int j=1;j<strs.size();++j){
                    if(strs[j][i]!=strs[0][i]) return ans;
                    if(j==strs.size()-1) ans.push_back(strs[0][i]);
                }
        }
        return ans;
    }
};


//
//substr简化一下
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](const auto& s1, const auto& s2){
            return s1.size()<s2.size();
        });
        for(int i=0;i<strs[0].size();++i){
                for(int j=1;j<strs.size();++j){
                    if(strs[j][i]!=strs[0][i]) return strs[0].substr(0,i);
                }
        }
        return strs[0];
    }
};
