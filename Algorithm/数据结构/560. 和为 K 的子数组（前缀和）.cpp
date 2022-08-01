//
//枚举（超时）
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;++i){       // 以i结尾的子数组
            int cur_sum=0;
            for(int j=i;j>=0;--j){
                cur_sum+=nums[j];
                if(cur_sum==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
