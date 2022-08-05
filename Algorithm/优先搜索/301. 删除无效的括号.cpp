//
//回溯+剪枝
//
class Solution {
public:
    vector<string> ans;

    bool isValid(string s){
        int cnt=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++cnt;
            }
            else if(s[i]==')'){
                --cnt;
                if(cnt<0) return false;   // 当前遍历到的「左括号」的数目严格小于「右括号」的数目则表达式无效
            }
        }
        return cnt==0;
    }

    void backtracking(string s, int start, int lremove, int rremove){
        if(lremove==0 && rremove==0){
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }
        for(int i=start;i<s.size();++i){
            if(i>start&& s[i]==s[i-1]) continue;      // 遇到连续相同的括号我们只需要搜索一次即可，比如当前遇到的字符串为 "(((())"，去掉前四个左括号中的任意一个，生成的字符串是一样的
            if(lremove+rremove>s.size()-i) return;    // 剩余未尝试的字符串的长度小于 lremove+rremove 时，则停止本次搜索
            if(lremove>0 && s[i]=='('){
                backtracking(s.substr(0,i)+s.substr(i+1),i,lremove-1,rremove);
            }
            if(rremove>0 && s[i]==')'){
                backtracking(s.substr(0,i)+s.substr(i+1),i,lremove,rremove-1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int lremove=0,rremove=0;
        for(int i=0;i<s.size();++i){  // 求「左括号」和「右括号」各自最少应该删除的数量
            if(s[i]=='('){
                ++lremove;
            }
            else if(s[i]==')'){
                if(lremove==0){
                    ++rremove;
                }
                else{
                    --lremove;
                }
            }
        }
        backtracking(s,0,lremove,rremove);
        return ans;
    }
};



// 
//广度优先搜索
//每一轮删除字符串中的 1 个括号，直到出现合法匹配的字符串为止，此时进行轮转的次数即为最少需要删除括号的个数
//用哈希表记录所有删除 1 个括号后可能的字符串
//
class Solution {
public:
    vector<string> ans;

    bool isValid(string s){
        int cnt=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++cnt;
            }
            else if(s[i]==')'){
                --cnt;
                if(cnt<0) return false;
            }
        }
        return cnt==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> curSet;
        curSet.insert(s);
        while(true){
            for(auto str:curSet){
                if(isValid(str)){
                    ans.push_back(str);
                }
            }
            if(ans.size()>0) return ans;    // 找到合法的字符串则返回，不再继续进行删除 
            unordered_set<string> nextSet;
            for(auto str:curSet){
                for(int i=0;i<str.size();++i){
                    if(i>0 && str[i]==str[i-1]) continue;
                    if(str[i]=='(' || str[i]==')'){
                        nextSet.insert(str.substr(0,i)+str.substr(i+1));      // 哈希表的insert可以避免插入重复值
                    }
                }
            }
            curSet=nextSet;     // 哈希表赋值
        }
    }
};
