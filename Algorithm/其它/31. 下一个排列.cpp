//
//排列 [4,5,2,6,3,1] 的下一个排列 [4,5,3,1,2,6]
//[4,5,2,6,3,2,1]  [4,5,2,1,2,3,6]是之前的排列，不是下一个排列
//
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]){  // '='相等的值需要跳过，因为 i 的右侧是递减的，不跳过则无法找到最小的比 i 大的 j
            i--;
        }
        if(i>=0){
            int j=nums.size()-1;
            while(j>i && nums[j]<=nums[i]){   // '='跳过相等的值，如果交换相等的值，后续从小到大0排序 i 的右侧得到的是之前的排列
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
