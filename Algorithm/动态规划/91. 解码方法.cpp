//
//dp[i]表示字符串s的前i个字符的解码方法数
//第i个字符单独解码有dp[i-1]种方法，结合第i-1个字符一起解码有dp[i-2]种方法，二者相加
//单独解码，字符不能为0；结合解码，前一个字符不能为0，且结合的数字不大于26
//
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]=='0') dp[1]=0;  //边界条件，s="0"和s="06"
        else dp[1]=1;
        for(int i=2;i<=n;++i){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(s[i-2]!='0' && (s[i-2]-'0')*10+(s[i-1]-'0')<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
