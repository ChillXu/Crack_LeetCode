//
//抑或运算
//a^a=0;a^0=a;a^b=b^a;
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int &n:nums){
            ans ^= n;
        }
        return ans;
    }
};

//
//利用哈希表的键值对<key,value>
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;   //<key,value>
        for(int i=0;i<nums.size();++i){
            if(!hash.count(nums[i])){
                hash.insert(make_pair(nums[i],1));
            }
            else{
                hash[nums[i]]=2;
            }
        }
        for(auto iter=hash.begin();iter!=hash.end();++iter){
            if(iter->second==1){
                return iter->first;
            }
        }
        return 0;
    }
};

//
//哈希表的begin()
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0;i<nums.size();++i){
            if(!hash.count(nums[i])){
                hash.insert(nums[i]);
            }
            else{
                hash.erase(nums[i]);
            }
        }
        return *hash.begin(); 
    }
};
