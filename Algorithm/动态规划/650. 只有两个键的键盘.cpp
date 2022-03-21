//
//dp[i]表示延展到长度i的最少操作次数
//
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1);
        for(int i=2;i<=n;++i){
            dp[i]=i;           //若dp[i]不能被整除，dp[i]=i，dp[2]=2(先复制全部，后粘贴一次)
            for(int j=2;j*j<=i;++j){     //超过sqrt(i)，j与i/j会重复
                if(i%j==0){
                    dp[i]=min(dp[i],dp[j]+dp[i/j]);  //若能被j整除，操作次数等价于把一个长度为1的A延展到长度为i/j（两边同除i）
                }
            }
        }
        return dp[n];
    }
};
