//
//1.栈存储索引
//2.heights左右两边加上0解决边界情况（如[2,4]，没有0则不会进入while循环）
//3.先出栈再计算w，否则左边界会计算错误（如[2,1,2]]）
//[0]->[0,2]->[0]->[0,1]->[0,1,2]->[0,1]
//                                  0 2 4
//
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        vector<int> newheights(n+2);
        newheights[0]=newheights[n+1]=0;
        newheights.insert(newheights.begin()+1,heights.begin(),heights.end());
        stack<int> stk;
        for(int i=0;i<n+2;++i){
            while(!stk.empty() && newheights[i]<newheights[stk.top()]){     // 表示以栈顶元素值为高的矩形面积可以确定
                int h=newheights[stk.top()];
                stk.pop();
                int w=i-stk.top()-1;
                int Area=h*w;
                maxArea=max(Area,maxArea);
            }
            stk.push(i);
        }
        return maxArea;
    }
};
