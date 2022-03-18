//
//从左上到右下进行一次动态搜索，再从右下到左上进行一次动态搜索，两次动态搜索即可完成四个方向上的查找
//不可直接四个方向求min再+1，因为存在方向上未更新的情况，一次遍历无法得到所有的最近值
//
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()) return {};
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX-1));   //求min，需要初始化为INT_MAX-1。若初始化为INX_MAX，更新时计算dp+1会溢出！
        for(int i=0;i<m;++i){        //左，上
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    if(i>0){
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    }
                    if(j>0){
                        dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=m-1;i>=0;--i){     //右，下
            for(int j=n-1;j>=0;--j){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    if(i<m-1){
                        dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                    }
                    if(j<n-1){
                        dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
                    }
                }
            }
        }
        return dp;
    }
};
