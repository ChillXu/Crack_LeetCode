//
//从数组的右上方开始查找，如果当前元素大于目标值，则移到左边一列；如果当前元素小于目标值，则移到下边一行
//
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        int row=matrix.size(),column=matrix[0].size();
        int m=0,n=column-1;
        for(;m<row && n>=0;){
            if(matrix[m][n]==target) return true;
            else if(matrix[m][n]>target) --n;
            else ++m;
        }
        return false;
    }
};
