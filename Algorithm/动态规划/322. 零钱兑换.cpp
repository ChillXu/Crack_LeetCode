//
//最小值完全背包问题
//注意点  1.dp的初始化值；
//       2.不压缩空间时需要写清else情况；
//       3.边界情况，动态规划完成后，不存在满足条件的情况。
//
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1)); //求min，所以初始化值为amount+1，硬币最多的组合方式就是只用1元，amount+1比任何可能的组合大
        for(int i=0;i<=n;++i){
            dp[i][0]=0;       //初始的状态值，amount为0时，需要的硬币个数为0
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=amount;++j){
                if(coins[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }
                else{        //更新else情况
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==amount+1?-1:dp[n][amount];    //！！！不存在满足条件的情况下，dp[n][amount]值仍为amount+1
    }
};
