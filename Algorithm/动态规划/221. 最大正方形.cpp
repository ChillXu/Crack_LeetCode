//
//dp(i,j)表示以(i,j)为右下角，且只包含1的正方形的边长最大值
//当前位置的元素值等于三个相邻位置的元素中的最小值加1
//
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        int m=matrix.size(),n=matrix[0].size();
        int max_side=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i){           //需要预留位置给dp[i-1][j]...
            for(int j=1;j<=n;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    max_side=max(max_side,dp[i][j]);
                }
            }
        }
        return max_side*max_side;
    }
};
