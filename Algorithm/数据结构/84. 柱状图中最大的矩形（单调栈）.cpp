//
//[2,1,2]
//
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int> stk;
        stack<int> index;
        for(int i=0;i<n;++i){
            while(!stk.empty() && heights[i]<stk.top()){
                int Area=stk.top()*(i-index.top());
                maxArea=max(Area,maxArea);
                stk.pop();
                index.pop();
            }
            stk.push(heights[i]);
            index.push(i);
            while(!stk.empty() && i==n-1){
                int Area=stk.top()*(i+1-index.top());
                maxArea=max(Area,maxArea);
                stk.pop();
                index.pop();
            }
        }
        return maxArea;
    }
};
