//
// dp[i]=max(dp[i-2]+nums[i],dp[i-1])
// 环形街区，考虑[0,n-2]和[1,n-1]即可涵盖所有的最大值情况
//
class Solution {
public:
    int robRange(vector<int>& nums,int start,int end){
        int first=nums[start],second=max(nums[start],nums[start+1]);
        int temp;
        for(int i=start+2;i<=end;++i){
            temp=second;
            second=max(first+nums[i],second);
            first=temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int length=nums.size();
        if(length==1){return nums[0];}
        else if(length==2){return max(nums[0],nums[1]);}
        else{
            return max(robRange(nums,0,length-2),robRange(nums,1,length-1));
        }
    }
};
