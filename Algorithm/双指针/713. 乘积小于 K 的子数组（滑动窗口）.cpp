//
//题目：给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        int product=1;
        int ans=0;
        for(;right<n;++right){
            product*=nums[right];
            while(left<=right && product>=k){   // '='很关键！！
                product/=nums[left];
                ++left;
            }
            ans+=right-left+1;          // 以右端点元素为末尾元素的子数组的个数
        }
        return ans;
    }
};
