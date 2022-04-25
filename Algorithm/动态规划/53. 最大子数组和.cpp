//
//dp[i]为以nums[i]结尾的子数组的最大和
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;++i){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//
//用pre_max记录以nums[i]结尾的子数组的最大和，ans记录最大和
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int pre_max=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            pre_max=max(nums[i],pre_max+nums[i]);
            ans=max(pre_max,ans);
        }
        return ans;
    }
};
