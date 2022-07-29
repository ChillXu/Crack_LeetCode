//
//题目：给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数，
//      假设 nums 只有一个重复的整数 ，返回这个重复的数。
//
//二分查找
//时间：O(nlogn)   空间：O(1)
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


//
//双指针
//时间：O(n)   空间：O(1)
//将数组下标 n 和数 nums[n] 建立一个映射关系 f(n)，其映射关系 n->f(n)
//数组中如果有重复的数，那么就会产生多对一的映射，这样形成的链表就一定会有环路了
//[1,3,4,2,2]
// 0,1,2,3,4
//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        slow=nums[slow];
        fast=nums[nums[fast]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];        // 第一次相遇之后，fast归零且每次只走一步
        }
        return slow;
    }
};
