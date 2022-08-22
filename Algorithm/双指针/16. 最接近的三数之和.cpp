//
//题目：给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
//a,b,c
//先排序，再遍历a；b指向i+1，指向n-1
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int ans;
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;++i){
            int left=i+1,right=n-1;
            while(left<right){
                int cur_sum=nums[i]+nums[left]+nums[right];
                if(cur_sum==target){
                    return target;
                }
                else if(cur_sum<target){
                    ++left;
                }
                else{
                    --right;
                }
                if(diff>abs(target-cur_sum)){
                    diff=abs(target-cur_sum);
                    ans=cur_sum;
                }
            }
        }
        return ans;
    }
};
