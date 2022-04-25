//
//dp[i]为以i结尾的数组的最大子树组和
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
