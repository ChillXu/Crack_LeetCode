//
//使用哈希表存储每个数字对应的所有可能的字母，然后进行回溯;
//回溯过程中维护一个字符串，表示已有的字母排列;
//当字符串达到输入digits的位数时入栈并回溯，使用数字对应的其它字母。
//
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string combination;
        if(digits.empty()){
            return res;
        }
        unordered_map<char,string> phonemap{      // 构建哈希表
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        backtracking(res,digits,0,combination,phonemap);
        return res;
    }

    void backtracking(vector<string>& res, string& digits, int level, string& combination, unordered_map<char,string>& phonemap){
        if(level==digits.size()){
            res.push_back(combination);
            return;       // 记得return！！！
        }
        string letters=phonemap.at(digits[level]);    // phonemap[digits[level]]也可以
        for(char c:letters){
            combination.push_back(c);
            backtracking(res,digits,level+1,combination,phonemap);
            combination.pop_back();
        }
    }
};
