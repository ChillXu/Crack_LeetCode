//
//题目：给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
//请你找出所有和为 0 且不重复的三元组。
//
//排序+双指针
//枚举的三元组 (a,b,c) 满足 a≤b≤c ，减少重复
//
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int first=0;first<n;++first){             // 枚举a
            if(first>0 && nums[first]==nums[first-1]){// 需要和上一次枚举的数不相同，nums[first]==nums[first+1]会越界
                continue;
            }
            int third=n-1;
            int target=-nums[first];
            for(int second=first+1;second<third;++second){    // b,c双指针
                if(second>first+1 && nums[second]==nums[second-1]){
                    continue;
                }
                while(nums[second]+nums[third]>target && second<third){
                    third--;
                }
                if(second>=third){                // 如果指针重合，随着 b 后续的增加就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                    break;
                }
                if(nums[second]+nums[third]==target){
                    ans.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return ans;
    }
};
