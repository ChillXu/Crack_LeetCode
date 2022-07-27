//
//从数组的右上方开始查找，如果当前元素大于目标值，则移到左边一列；如果当前元素小于目标值，则移到下边一行
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int r=0,c=n-1;
        while(r<m && c>=0){
            if(target==matrix[r][c]) return true;
            else if(target>matrix[r][c]) ++r;
            else --c;
        }
        return false;
    }
};


//
//因为矩阵的每行都是升序排列的，可以逐行二分查找
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(const auto& row:matrix){
            auto it=lower_bound(row.begin(),row.end(),target);
            if(it!=row.end() && *it==target){
                return true;
            }
        }
        return false;
    }
};
