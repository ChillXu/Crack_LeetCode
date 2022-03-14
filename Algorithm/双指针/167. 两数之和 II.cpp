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
