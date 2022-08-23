//
//题目：给你一个整数数组 nums，返回数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//
//乘积 = 当前数左边的乘积 * 当前数右边的乘积
//时间：O(n)  空间：O(1)  （输出数组不被视为额外空间）
//
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=1;
        int k=1;
        for(int i=1;i<n;++i){
            ans[i]=ans[i-1]*nums[i-1];    // ans[i]表示当前数nums[i]左边的乘积，即先计算前缀和
        }
        for(int i=n-1;i>=0;--i){
            ans[i]*=k;
            k*=nums[i];
        }
        return ans;
    }
};
