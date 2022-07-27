//
//题目：给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
//
//
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;     // 栈记录括号的索引
        int start=0;
        int maxlen=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                if(stk.empty()){      // 当遍历到右括号')'且此时栈为空时，记录下一个可能的括号子串开始的位置start
                    start=i+1;        // 出栈后栈为空的情况下，start可以用来计算括号子串的长度；栈不为空，则可以通过栈顶来计算长度
                }
                else{
                    stk.pop();
                    if(stk.empty()){
                        maxlen=max(maxlen,i-start+1);
                    }
                    else{
                        maxlen=max(maxlen,i-stk.top());
                    }
                }
            }
        }
        return maxlen;
    }
};
