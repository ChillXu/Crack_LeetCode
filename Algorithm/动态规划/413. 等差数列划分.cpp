//
//定义状态：dp[i]表示从nums[0]到nums[i]且以nums[i]为结尾的等差数列子数组的数量
//如果nums[i]能和nums[i-1]nums[i-2]组成等差数列，则以nums[i-1]结尾的等差数列均可以nums[i]结尾，且多了一个新等差数列[nums[i],nums[i-1],nums[i-2]]
//
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        vector<int> dp(n,0);
        for(int i=2;i<n;++i){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
