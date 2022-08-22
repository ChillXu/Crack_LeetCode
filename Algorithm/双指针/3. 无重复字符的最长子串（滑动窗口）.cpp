//
//题目：给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的 长度 。
//
//滑动窗口（维持一个队列）
//用哈希表记录已有字符，右边不满足时（出现重复字符）移动左边，同时删除哈希表中对应字符直到满足条件后，继续移动右边
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num=s.length(),maxlen=0;
        unordered_set<char> hash;
        int left=0,right=0;
        for(;right<num;++right){
            while(hash.find(s[right])!=hash.end()){
                hash.erase(s[left]);
                left++;
            }
            hash.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
