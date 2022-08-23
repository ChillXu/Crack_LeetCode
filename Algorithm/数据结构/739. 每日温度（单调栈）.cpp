//
//题目：给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
//其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//
//单调栈
//
//维持一个单调栈，温度比栈顶低的进栈，比栈顶高的，栈顶出栈并返回索引差，然后继续比较下一个栈顶...比完进栈
//
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> indices;
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            while(!indices.empty()){
                int pre_index=indices.top();
                if(temperatures[i]<=temperatures[pre_index]){
                    break;
                }
                indices.pop();
                ans[pre_index]=i-pre_index;
            }
            indices.push(i);
        }
        return ans;
    }
};
