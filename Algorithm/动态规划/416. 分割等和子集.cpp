//
//等价于0-1背包问题，设所有数字和为sum，我们的目标是选取一部分物品，使得它们的总和为sum/2
//dp[i][j]表示nums中下标[0,i-1]范围内，总和为j的子集是否存在
//
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1,false));
        if(sum%2) return false;      //边界条件！
        for(int i=0;i<=n;++i){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=sum/2;++j){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum/2];
    }
};
