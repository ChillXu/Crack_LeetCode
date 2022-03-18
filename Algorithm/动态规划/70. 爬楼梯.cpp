//
//每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达
//
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,1);  //初始化！！！保证dp[1]和dp[2]为正确
        for(int i=2;i<=n;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
