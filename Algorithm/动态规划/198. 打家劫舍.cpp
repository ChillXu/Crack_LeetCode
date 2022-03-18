//
//dp[i]抢与不抢，不抢劫这个房子，此时累计的金额即为dp[i-1]；抢劫这个房子，那么此前累计的最大金额只能是dp[i-2]
//
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[1]=nums[0];
        for(int i=2;i<=n;++i){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]); //nums[i-1]对应第i个房子的金额
        }
        return dp[n];
    }
};
