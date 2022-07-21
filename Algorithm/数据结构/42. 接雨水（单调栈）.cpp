//
//维护一个单调递减栈（栈尾大于栈头）
//如果当前遍历的元素（柱子）高度小于栈顶元素的高度，就把这个元素加入栈中；
//如果当前遍历的元素（柱子）高度大于等于栈顶元素的高度，则栈顶出栈，并将下一个栈顶元素作为最左边的柱子，计算二者间的雨水；
//直至栈为空或栈顶元素大于当前遍历元素，当前遍历元素入栈。
//
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;         // 记录下标，方便计算宽度 w
        int current=0;
        int sum=0;
        while(current<height.size()){
            while(!stk.empty() && height[current]>=height[stk.top()]){
                int top=stk.top();
                stk.pop();
                if(stk.empty()){    // 出栈后，栈为空，左边没有柱子可以接雨水
                    break;
                }
                int h=min(height[stk.top()],height[current])-height[top];       // 单调栈，height[stk.top()] 一定比 height[top] 大
                int w=current-stk.top()-1;
                sum += h*w;
            }
            stk.push(current);
            current++;
        }
        return sum;
    }
};
