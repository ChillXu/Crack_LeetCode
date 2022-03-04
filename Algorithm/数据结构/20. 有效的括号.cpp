\\
\\左括号进站，遇到右括号，判断栈顶元素是否匹配
\\
class Solution {
public:
    bool isValid(string s) {
        stack<char> parse;
        for(int i=0;i<s.length();++i){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
                parse.push(s[i]);
            }
            else{
                if(parse.empty()){return false;}
                if(s[i]=='}' && parse.top()=='{'||
                   s[i]==']' && parse.top()=='['||
                   s[i]==')' && parse.top()=='('){
                       parse.pop();
                }
                else{
                    return false;
                }
            }
        }
        return parse.empty();
    }
};
