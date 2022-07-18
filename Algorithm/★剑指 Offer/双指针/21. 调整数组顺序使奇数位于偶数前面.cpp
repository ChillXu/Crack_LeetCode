//
//首尾双指针
//
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            while(l<r && nums[l]%2!=0){   //不满足l<r说明已经移动判断到位了
                l++;
            }
            while(l<r && nums[r]%2==0){
                r--;
            }
            swap(nums[l],nums[r]);     //学会直接调用swap
        }
        return nums;
    }
};
