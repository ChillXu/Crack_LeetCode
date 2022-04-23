//
//题目：给你一个整数数组nums，数组中的元素互不相同。返回该数组所有可能的子集（幂集）
//
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());  //空集必为子集
        int n=nums.size();
        for(int i=1;i<=n;++i){         //考虑子集内的元素个数i
            vector<int> sub(i,0);
            backtracking(ans,sub,0,i,0,nums);
        }
        return ans;
    }

    void backtracking(vector<vector<int>> &ans,vector<int> &sub,int count,int k,int pos,vector<int> &nums){
        if(count==k){
            ans.push_back(sub);
            return;
        }
        for(int i=pos;i<nums.size();++i){
            sub[count++]=nums[i];
            backtracking(ans,sub,count,k,i+1,nums);
            count--;
        }
    }
};
