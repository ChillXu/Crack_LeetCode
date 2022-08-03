//
//把 (i,k) 开区间所有气球戳爆，然后把戳爆这些气球的所有金币都收入囊中，金币数量记录在 dp[i][k]
//同理 (k,j) 开区间你也已经都戳爆了，钱也拿了，记录在 dp[k][j]
//
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        vector<int> new_nums(n+2);
        new_nums[0]=new_nums[n+1]=1;    //创建一个辅助数组，并在首尾各添加1，方便处理边界情况
        for(int i=1;i<=n;++i){
            new_nums[i]=nums[i-1];
        }
        for(int len=3;len<=n+2;++len){         //len表示开区间长度（对每一个区间长度进行循环）
            for(int l=0;l<=n+2-len;++l){       //l表示开区间左端点, l+len-1 则表示开区间右端点
                for(int k=l+1;k<l+len-1;++k){  //k为开区间内的索引（代表区间最后一个被戳破的气球）
                    int left=dp[l][k];
                    int right=dp[k][l+len-1];
                    int sum=left+right+new_nums[l]*new_nums[k]*new_nums[l+len-1];
                    dp[l][l+len-1]=max(dp[l][l+len-1],sum);
                }
            }
        }
        return dp[0][n+1];
    }
};
