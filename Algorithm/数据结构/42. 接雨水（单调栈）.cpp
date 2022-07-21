//
//维护一个单调递减栈（栈尾大于栈头）
//每次
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
                if(stk.empty()){    // 
                    break;
                }
                int h=min(height[stk.top()],height[current])-height[top];
                int w=current-stk.top()-1;
                sum += h*w;
            }
            stk.push(current);
            current++;
        }
        return sum;
    }
};
