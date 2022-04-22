//
//双指针，一头一尾
//每次移动对应数字较小的那个指针
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        while(left<right){
            int Area=min(height[left],height[right])*(right-left);
            ans=max(Area,ans);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};
