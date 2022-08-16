//
//自己写的
//
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;     // -123不是回文数
        vector<int> nums;
        while(x){
            nums.push_back(x%10);
            x/=10;
        }
        int n=nums.size();
        for(int i=0,j=n-1;i<j;++i,--j){
            if(nums[i]!=nums[j]){
                return false;
            }
        }
        return true;
    }
};


//
//反转一半数字
//时间复杂度：O(logn)，对于每次迭代，我们会将输入除以10
//空间复杂度：O(1)
//
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x%10==0&&x!=0){
            return false;
        }
        int reverseNum=0;
        while(x>reverseNum){
            reverseNum=reverseNum*10+x%10;
            x/=10;
        }
        return x==reverseNum || x==reverseNum/10;
    }
};
