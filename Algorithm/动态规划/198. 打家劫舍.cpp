//
//题目：如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
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
