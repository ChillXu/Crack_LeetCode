//
//哈希表
//时间：O(n)   空间：O(n) 
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> hash;
        int i;
        for(i=0;i<n;++i){
            hash[nums[i]]++;
            if(hash[nums[i]]>n/2) break;
        }
        return nums[i];
    }
};

//
//排序，返回众数
//时间：O(nlogn)   空间：O(logn) 
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//
//摩尔投票
//时间：O(n)   空间：O(1) 
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate;
        for(int num:nums){
            if(count==0){candidate=num;}
            if(candidate==num){count++;}    // 相同就加一票，不同就减一票，最后只有众数会剩下
            else{count--;}
        }
        return candidate;
    }
};
