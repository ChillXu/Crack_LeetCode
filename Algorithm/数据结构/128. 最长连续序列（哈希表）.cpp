//
//题目：给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
//
//排序 时间复杂度O(nlogn)
//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxLen=1;
        int tmp=1;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1]){
                continue;
            }
            if(nums[i+1]-nums[i]==1){
                tmp++;
            }
            else{
                tmp=1;
            }
            maxLen=max(maxLen,tmp);
        }
        return maxLen;
    }
};


//
//哈希表 时间复杂度O(2n)
//外层for循环O(n)，while循环在整个for循环过程中只会将哈希表每个元素遍历一遍
//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto x:nums) hash.insert(x);
        int maxLen=0;
        int curLen;
        for(auto x:hash){
            if(!hash.count(x-1)){         // 元素x的不存在比它小1的元素，说明x是一个序列的开头；如果存在，则直接跳过
                curLen=1;
                while(hash.count(x+1)){
                    curLen++;
                    x++;
                }
                maxLen=max(maxLen,curLen);
            }
        }
        return maxLen;
    }
};
