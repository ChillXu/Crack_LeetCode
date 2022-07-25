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
        vector<int>
    }
};
