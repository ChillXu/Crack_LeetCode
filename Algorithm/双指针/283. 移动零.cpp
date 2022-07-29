//
//题目：给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
//
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        for(int i=0;i<n;++i){
            if(nums[i]!=0){
                swap(nums[i],nums[pos++]);      // 当nums[i]不为0时，将其交换到pos的位置
            }                                   // 因为是从头到尾遍历数组，遇到的肯定是左边第一个不为0的元素，不用担心出现与前面非0元素交换的情况
        }
    }
};
