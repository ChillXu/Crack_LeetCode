\\
\\ for(const int & num: nums) 迭代容器中所有的元素
\\
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(const int & num: nums){    \\若需要对序列中的元素进行写操作，则需要声明成引用类型 &
            int pos = (num-1)%n;       \\对应位置的数+n之后再整除n，不影响在数组中的pos
            nums[pos] += n;
        }
        for(int i=0;i<n;++i){
            if(nums[i]<=n){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(const int & num: nums){
            int pos = abs(num)-1;    \\需要取绝对值，数组nums中可能存在重复的数字，不加abs数组访问会越界
            if(nums[pos]>0){
                nums[pos] = -nums[pos];   \\取负号也不影响在数组中的下标
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
