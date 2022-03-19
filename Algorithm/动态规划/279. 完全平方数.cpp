//
//dp[i]表示数字i最少可以由几个完全平方数相加构成
//dp[i]由最小的(dp[i-k^2]+1)决定
//
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;                     //初始化dp[0]，否则下面计算dp[1]会溢出
        for(int i=1;i<=n;++i){
            for(int j=1;j*j<=i;++j){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
