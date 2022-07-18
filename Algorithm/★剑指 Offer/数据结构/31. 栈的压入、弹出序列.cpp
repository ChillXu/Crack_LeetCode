//
//用栈去模拟入栈、出栈，当栈顶元素和出栈序列元素相同时出栈
//
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0;
        for(int num:pushed){
            stk.push(num);
            while(!stk.empty() && stk.top()==popped[i]){
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};
