//
//**荷兰国旗问题**
//单指针遍历两遍
//
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                swap(nums[ptr++],nums[i]);
            }
        }
        for(int i=ptr;i<nums.size();++i){
            if(nums[i]==1){
                swap(nums[ptr++],nums[i]);
            }
        }
    }
};


//
//双指针遍历一遍
//
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        for(int i=0;i<=r;++i){
            while(i<=r && nums[i]==2){      // i<=r的结束条件很关键，例如[2]
                swap(nums[i],nums[r--]);    // 因为数组尾部的元素没有遍历过，所以需要while循环来一直判断nums[i]是否为2
            }                               
            if(nums[i]==0){                 // 数组头部元素已经遍历，无需再判断交换后的nums[i]是否为0
                swap(nums[i],nums[l++]);
            }
        }
    }
};
