//
//熟悉lower_bound和upper_bound函数
//
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return vector<int>{-1,-1};
        }
        int lower=lower_bound(nums,target);
        int upper=upper_bound(nums,target)-1;
        if(lower==nums.size()||nums[lower]!=target){  //前一个条件target过大，后一个target过小，查询不到
            return vector<int>{-1,-1};
        }
        return vector<int>{lower,upper};
    }
    int lower_bound(vector<int>& nums, int target){
        int l=0,r=nums.size(),mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]>=target){    // >= 若nums[mid]等于target，右指仍然针会一直更新
                r=mid;  //左闭右开
            }
            else{
                l=mid+1;     //不断更新l，直到到达r的位置
            }
        }
        return l;
    }
    int upper_bound(vector<int>& nums, int target){
        int l=0,r=nums.size(),mid;
        while(l<r){
            mid=l+(r-l)/2;
            if(nums[mid]>target){    // > 右指针会停在大于target的位置
                r=mid;  //左闭右开
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
