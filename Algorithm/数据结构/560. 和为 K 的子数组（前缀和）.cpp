//
//枚举（超时）
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;++i){       // 以i结尾的子数组
            int cur_sum=0;
            for(int j=i;j>=0;--j){
                cur_sum+=nums[j];
                if(cur_sum==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



//
//将和为K转化为前缀和之差为K，若[j,i]的和为K，则prefix[i]-prefix[j-1]=K
//所以遍历nums计算prefix[i]，判断prefix[i]-K是否在哈希表中，若存在则和为K的子数组存在
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        int prefix=0;
        unordered_map<int,int> hash;    // 哈希表记录已经计算的前缀和
        hash[0]=1;
        for(int i=0;i<n;++i){
            prefix+=nums[i];
            if(hash.count(prefix-k)){
                cnt+=hash[prefix-k];
            }
            hash[prefix]++;         // 可能存在不同的i但是前缀和相同的情况，所以需要累加
        }
        return cnt;
    }
};
