//
//题目：给你一个升序排列的数组 nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int cnt=1;
        for(int l=0,r=1;r<n;++r){
            if(nums[r]!=nums[l]){
                swap(nums[r],nums[++l]);
                ++cnt;
            }
        }
        return cnt;
    }
};
