//
//将左右括号的个数 open 和 close 加到 backtracking 的参数中
//只有当 close<open 时才考虑添加右括号')'
//
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string brackets;
        backtracking(res,brackets,n,0,0);
        return res;
    }

    void backtracking(vector<string>& res, string& brackets, int n, int open, int close){
        if(brackets.size()==2*n){
            res.push_back(brackets);
            return;
        }
        if(open<n){
            brackets.push_back('(');
            backtracking(res,brackets,n,open+1,close);
            brackets.pop_back();
        }
        if(close<open){
            brackets.push_back(')');
            backtracking(res,brackets,n,open,close+1);
            brackets.pop_back();
        }
    }
};
