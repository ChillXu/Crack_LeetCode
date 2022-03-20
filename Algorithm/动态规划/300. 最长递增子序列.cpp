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


//
//贪心+二分查找
//遍历每一个位置i，如果其对应的数字大于dp数组中所有数字的值，那么我们把它放在dp数组尾部，表示最长递增子序列长度加1; 
//如果我们发现这个数字在dp数组中比数字a大、比数字b小，则我们将b更新为此数字，使得之后构成递增序列的可能性增大。
//
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                auto iter=lower_bound(dp.begin(),dp.end(),nums[i]);
                *iter=nums[i];
            }
        }
        return dp.size();
    }
};

/*
[10,9,2,5,3,7,101,18,4]
num dp
10 [10]
9 [9]
2 [2]
5 [2,5]
3 [2,3]
7 [2,3,7]
101 [2,3,7,101] 
18 [2,3,7,18]
4 [2,3,4,18]   虽然不是最长递增子序列，但是不影响序列的长度，如果数组后面还有数（如6、8）则依然可以正确更新
*/
