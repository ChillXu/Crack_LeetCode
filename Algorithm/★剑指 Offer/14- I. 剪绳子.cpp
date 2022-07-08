//
//动态规划
//dp[i]表示长度为 i 的绳子剪成 m 段的最大乘积
//     1.分成 j 和 i-j，如果继续分j，则最大乘积为dp[j]*(i-j)
//     2.如果不继续分j，则最大乘积为j*(i-j)
//
  
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1);
        dp[2]=1;
        for(int i=3;i<=n;++i){
            for(int j=1;j<i;++j){
                dp[i]=max(dp[i],max(dp[j]*(i-j),j*(i-j)));
            }
        }
        return dp[n];
    }
};
