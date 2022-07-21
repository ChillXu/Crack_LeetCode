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
