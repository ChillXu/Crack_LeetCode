//
//与1143最长公共子序列类似
//dp[i][j]表示第一个字符串到位置i，第二个字符串到位置j为止，最多需要几步编辑
//dp[i][j-1]+1 表示在word1的位置i后插入word2中位置j的字符，一次操作即可得到dp[i][j]
//（已得到word1[0,...,i]变为word2[0,...,j-1]的操作次数，word1[0,...,i]变为word2[0,...,j]只需要在word1后添加j或者在word2后删除j）
//
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){  //初始化！
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1), min(dp[i][j-1]+1, dp[i-1][j]+1));
                }
            }
        }
        return dp[m][n];
    }
};
