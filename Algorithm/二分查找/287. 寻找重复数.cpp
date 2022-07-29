//
//题目：给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数，
//      假设 nums 只有一个重复的整数 ，返回这个重复的数。
//
//二分查找
//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=n-1;    // 数字范围[1,n-1]
        while(left<right){
            int mid=(left+right)/2;
            int cnt=0;
            for(auto num:nums){
                if(num<=mid){
                    cnt++;
                }
            }
            if(cnt>mid){    // 如果cnt个数放入mid个抽屉，必有数放入同一个抽屉（抽屉原理）
                right=mid;
            }
            else left=mid+1;
        }
        return left;
    }
};
