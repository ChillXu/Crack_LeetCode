\\
\\排列回溯
\\input: [1,2,3]
\\output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
\\
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtracking(nums,0,ans);
        return ans;
    }

    void backtracking(vector<int>& nums, int level,vector<vector<int>>& ans){   \\level记录递归的层
        if(level==nums.size()-1){
            ans.push_back(nums);
            return;                                                              \\return很关键！！！
        }
        for(int i=level;i<nums.size();++i){
            swap(nums[level],nums[i]);
            backtracking(nums,level+1,ans);
            swap(nums[level],nums[i]);
        }
    }
};
