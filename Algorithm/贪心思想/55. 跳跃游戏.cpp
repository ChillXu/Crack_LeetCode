/*
给定一个非负整数数组 nums ，你最初位于数组的第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
*/
//
//遍历数组中的每一个位置，并实时维护最远可以到达的位置
//如果最远可以到达的位置大于等于数组中的最后一个位置，那就说明最后一个位置可达
//
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlen=0;
        for(int i=0;i<nums.size();++i){
            if(i>maxlen) return false;
            maxlen=max(maxlen,i+nums[i]);
        }
        return true;
    }
};
