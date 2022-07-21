//
//排列 [4,5,2,6,3,1] 的下一个排列 [4,5,3,1,2,6]
//[4,5,2,6,3,2,1]  [4,5,2,1,2,3,6]是之前的排列，不是下一个排列
//
//从排列右边开始，先找到第一个满足nums[i]<nums[i+1]的元素i，然后再从排列右边找到第一个比元素i大的元素j，二者交换，并且将右侧从小到大排序
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
            while(j>i && nums[j]<=nums[i]){   // '='跳过相等的值，如果交换相等的值，后续从小到大排序 i 的右侧得到的是之前的排列
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};
