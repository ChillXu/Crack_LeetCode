\\
\\nums=[3,1,2,3,3,3,3]
\\nums=[3,3,3,3,1,2,3] 无法判断左边有序还是右边有序
\\
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int mid;
        while(start<=end){  \\ "="很关键，最终判断 
            mid=(start+end)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[start]==nums[mid]){
                ++start;
            }
            else if(nums[start]<nums[mid]){
                if(nums[mid]>target && nums[start]<=target){   \\ target需要在整个区间内，左右都要判断
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<target && nums[end]>=target){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};
