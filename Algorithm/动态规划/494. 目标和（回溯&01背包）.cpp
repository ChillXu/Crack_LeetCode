//
//题目：给你一个整数数组 nums 和一个整数 target 。
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个表达式，
//返回可以通过上述方法构造的、运算结果等于 target 的不同表达式的数目。
//
//回溯
//时间：O(2^n)   空间：O(n) 
//2^n种不同的表达式    栈的深度为n
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtracking(nums,target,0,0);
    }

    int backtracking(vector<int>&nums, int target, int level, int cur_sum){
        if(level==nums.size()){
            return cur_sum==target?1:0;
        }
        return backtracking(nums,target,level+1,cur_sum+nums[level]) +
                backtracking(nums,target,level+1,cur_sum-nums[level]);
    }
};


//
//动态规划
//时间：O(n×(sum−target))   空间：O(n×neg) 
//记数组的元素和为 sum，添加 - 号的元素之和为 neg，则其余添加 + 的元素之和为 sum−neg
//(sum-neg)-neg=target  =>  neg=(sum-target)/2      sum-target为非负偶数
//问题转化成在数组 nums 中选取若干元素，使得这些元素之和等于 neg，即0-1背包问题
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        int diff=sum-target;
        if(diff<0 || diff%2!=0) return 0;
        int neg=diff/2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(neg+1));     // n+1很关键！！n=0表示nums中没有元素可取时，对应的方案数为1
        dp[0][0]=1;     // nums=[1,0],target=1,此时neg=0,因为nums中存在元素0,dp[2][0]不一定等于1
        for(int i=1;i<=neg;++i){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=neg;++j){      // j从0开始
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][neg];
    }
};

//
//空间优化
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        int diff=sum-target;
        if(diff<0 || diff%2!=0) return 0;
        int neg=diff/2;
        int n=nums.size();
        vector<int> dp(neg+1);
        dp[0]=1;     
        for(auto num:nums){               // dp[i][j]只与dp[i-1][]相关，即dp每一行计算只与上一行有关
            for(int j=neg;j>=num;--j){    // 从后向前遍历，保证更新的加上的dp[j-num]是由dp[i-1][]而来，从前向后遍历会导致可能后面加上的dp[j-num]在前面的遍历已经更新
                dp[j]+=dp[j-num];
            }
        }
        return dp[neg];
    }
};
