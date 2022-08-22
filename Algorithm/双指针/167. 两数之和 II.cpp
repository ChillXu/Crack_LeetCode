//
//题目：给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列 ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
//
//numbers数组已经排序，只需要方向相反的双指针来遍历
//
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        int sum;
        while(l<r){
            sum=numbers[l]+numbers[r];
            if(sum==target){
                break;
            }
            else if(sum<target){++l;}
            else --r;
        }
        return vector<int>{l+1,r+1};  //直接能够返回容器
    }
};
