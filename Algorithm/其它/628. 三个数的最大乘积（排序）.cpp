//
//题目：给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-3]*nums[n-2]*nums[n-1]);
    }
};


//
//线性扫描直接从数组中找到  第一小、第二小 & 第一大、第二大、第三大  的五个数
//
//
