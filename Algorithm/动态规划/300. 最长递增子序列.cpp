//
//dp[i]表示以i结尾的最长子序列长度
//对于每一个位置i，如果其之前的某个位置j所对应的数字小于位置i所对应的数字，则可以获得一个以i结尾的、长度为 dp[j]+1 的子序列
//
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);  //10,3,4; 初始化需要为1
        int max_len=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            max_len=max(max_len,dp[i]);
        }
        return max_len;
    }
};
