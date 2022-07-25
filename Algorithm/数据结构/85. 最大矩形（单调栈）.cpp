class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int maxArea=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                heights[j]+=matrix[i][j];
            }
            maxArea=max(maxArea,largestRectangleArea(heights));
        }
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights){
        int n=heights.size();
        vector<int> newheights(n+2);
        newheights[0]=newheights[n+1]=0;
        newheights.insert(newheights.begin()+1,heights.begin(),heights.end());
        stack<int> stk;
        int curA,maxA=0;
        for(int i=0;i<n+2;++i){
            while(!stk.empty() && newheights[i]<newheights[stk.top()]){
                int h=newheights[stk.top()];
                stk.pop();
                int w=i-stk.top()-1;
                curA=h*w;
                maxA=max(maxA,curA);
            }
            stk.push(i);
        }
        return maxA;
    }
};
