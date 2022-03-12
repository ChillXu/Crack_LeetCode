\\
\\hash表记录每个元素出现的次数（hash表更好，用数组无法知道所申请的数组大小）
\\然后桶排序，桶号为频次，桶内元素为对应频次元素
\\
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int maxFrequent=0;
        for(const int & num:nums){
            maxFrequent=max(maxFrequent,++count[num]);//hash表记录每个元素出现的次数
        }
        //桶排序
        vector<vector<int>> buckets(maxFrequent+1);//桶数需要+1，因为这里不用下标为0的桶
        for(const auto & p:count){
            buckets[p.second].push_back(p.first);//桶号对应频次
        }
        //输出k个元素
        vector<int> ans;
        for(int i=maxFrequent;i>0 && ans.size()<k;--i){
            for(const int & num:buckets[i]){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
