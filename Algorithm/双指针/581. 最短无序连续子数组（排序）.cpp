//
//将给定的数组 nums 表示为三段子数组拼接的形式，分别记作 numsA,numsB,numsC
//找最短的numsB，即找最长的numsA和numsC的长度之和
//拷贝nums数组，两次遍历找边界
//时间：O(nlogn)   空间：O(n)
//
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(),numsSorted.end());
        int left=0;
        while(nums[left]==numsSorted[left]) left++;
        int right=nums.size()-1;
        while(nums[right]==numsSorted[right]) right--;
        return right-left+1;
    }
};



//
//一次遍历
//时间：O(n)   空间：O(1)
//
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxn=INT_MIN,right=-1;
        int minn=INT_MAX,left=-1;
        for(int i=0;i<n;++i){
            if(maxn>nums[i]){       // numsC的所有元素都比numsB的任一元素大，从左到右记录当前遍历的最大值，找到最后一个比最大值小的元素，即为右边界
                right=i;
            }
            else{
                maxn=nums[i];
            }
            if(minn<nums[n-i-1]){      // numsA的所有元素都比numsB的任一元素小，从右到左记录当前遍历的最小值，找到最后一个比最小值大的元素，即为左边界
                left=n-i-1;
            }
            else{
                minn=nums[n-i-1];
            }
        }
        return right==-1?0:right-left+1;
    }
};
