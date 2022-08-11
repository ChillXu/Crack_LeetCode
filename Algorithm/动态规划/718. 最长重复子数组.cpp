//
//题目：给两个整数数组 nums1 和 nums2 ，返回 两个数组中公共的、长度最长的子数组的长度。
//
//令 dp[i][j] 表示 A[i:] 和 B[j:] 的最长公共前缀，
//如果 A[i] == B[j]，那么我们知道 A[i:] 与 B[j:] 的最长公共前缀为 A[i + 1:] 与 B[j + 1:] 的最长公共前缀的长度加一，
//否则 A[i:] 与 B[j:] 的最长公共前缀为零,（从后向前遍历更新）
//那么答案即为所有 dp[i][j] 中的最大值。
//
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                }
                else dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};


//
//滑动对齐
//重叠过程可以分为三个过程：
//1. 上面子串进入，开始重叠的过程
//2. 上下两子串完全重叠，中间过程
//3. 上面的子串开始离开，重叠区域减少，离开过程
//
class Solution {
public:
    int maxLen(vector<int>& nums1, int i, vector<int>& nums2, int j, int len) {
        int cnt=0;
        int res=0;
        for(int k=0;k<len;++k){
            if(nums1[i+k]==nums2[j+k]) ++cnt;
            else{
                res=max(res,cnt);
                cnt=0;
            }
        }
        return max(res,cnt);
    }
    int findMax(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int res=0;
        /*
        A:           |*|*|*|*|
        B: |*|*|*|*|*|*|
                 ↓
        A:       |*|*|*|*|
        B: |*|*|*|*|*|*|
         */
        for(int i=1;i<m;++i){
            res=max(res,maxLen(nums1,0,nums2,n-i,i));
        }
        /*
        A:     |*|*|*|*|
        B: |*|*|*|*|*|*|
                 ↓
        A: |*|*|*|*|
        B: |*|*|*|*|*|*|
         */
        for(int i=n-m;i>=0;--i){
            res=max(res,maxLen(nums1,0,nums2,i,m));
        }
        /*
        A: |*|*|*|*|
        B:   |*|*|*|*|*|*|
                 ↓
        A: |*|*|*|*|
        B:       |*|*|*|*|*|*|
         */
        for(int i=1;i<m;++i){
            res=max(res,maxLen(nums1,i,nums2,0,m-i));
        }
        return res;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return nums1.size()<nums2.size()?findMax(nums1,nums2):findMax(nums2,nums1);
    }
};
