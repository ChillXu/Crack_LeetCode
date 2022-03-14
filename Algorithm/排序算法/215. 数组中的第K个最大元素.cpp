//
//快速选择，利用快排找到第k大的pivot即可
//
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left=0, right=nums.size()-1;
        int target=nums.size()-k;
        int mid;
        while(left<right){
            mid=quickSelection(nums,left,right);
            if(mid==target){
                return nums[mid];
                }
                if(mid>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
        }
        return nums[left];  //left==right时，若还没找到，则所求即为nums[left]
    }
    int quickSelection(vector<int>& nums, int left, int right){
        int i=left+1, j=right;
        while(true){
            while(i<right && nums[i]<=nums[left]){
                ++i;
            }
            while(j>left && nums[j]>=nums[left]){
                --j;
            }
            if(i>=j){break;}        // while(i<j){}的情况下，不满足条件的i、j会再执行一次swap
            swap(nums[i],nums[j]);
        }
        swap(nums[left],nums[j]);
        return j;
    }
};
