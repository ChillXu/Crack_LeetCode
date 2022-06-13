//
//hash表初始化为false；利用索引，将nums[i]通过swap交换到nums[nums[i]]处
//
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> hash;
        for(int i=0;i<nums.size();++i){
            if(hash[nums[i]]) return nums[i];
            else hash[nums[i]]=true;
        }
        return -1;
    }
};
