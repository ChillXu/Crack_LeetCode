//
//动态规划，空间复杂度O(n)
//
class Solution {
public:
    int numWays(int n) {
        if(n==0 || n==1) return 1;
        int MOD=1000000007;
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return dp[n];
    }
};

//
//动态规划，空间复杂度O(1)
//
class Solution {
public:
    int numWays(int n) {
        if(n==0 || n==1) return 1;
        int MOD=1000000007;
        int p=1,q=1,r;
        for(int i=2;i<=n;++i){
            r=(p+q)%MOD;
            p=q;
            q=r;
        }
        return r;
    }
};
