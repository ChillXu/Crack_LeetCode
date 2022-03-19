//
//dp[i]表示字符串s前i个字符组成的字符串s[0..i−1]是否能被空格拆分成若干个字典中出现的单词
//每个位置i，遍历字符串集合，查找集合中是否存在单词word能够由i位置向前的len长度的单词拆分而来。若存在，则问题分解，求dp[i-len]的或
//
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;++i){
            for(const string &word:wordDict){
                int len=word.length();
                if(i>=len && s.substr(i-len,len)==word){
                    dp[i]=dp[i] || dp[i-len];
                }
            }
        }
        return dp[n];
    }
};
