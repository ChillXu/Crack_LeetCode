//
//(难)
//dp[i][j]表示以 i 截止的字符串是否可以被以 j 截止的正则表达式匹配
//
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;            //s为空，p为空，匹配
        for(int i=1;i<=n;++i){    //s为空，p不为空，要想匹配，只可能右端是'*'，干掉一个字符后把p变为空串
            if(p[i-1]=='*'){
                dp[0][i]=dp[0][i-2];  //不用担心溢出问题，题目不会让'*'出现在p[0]
            }
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]!='*'){     //右端的p[j-1]为普通字符
                    dp[i][j]=dp[i-1][j-1] && s[i-1]==p[j-1];
                }
                else if(s[i-1]!=p[j-2] && p[j-2]!='.'){  //p[j-1]为'*'，只能p[j-1]星号干掉p[j-2]，继续考察剩余字符串s(0,i-1)和p(0,j-3)
                    dp[i][j]=dp[i][j-2];
                }
                else{                                    //p[j-1]为'*'，s[i-1]==p[j-2] || p[j-2]=='.'，考虑三种情况
                    dp[i][j]=dp[i][j-2] || dp[i-1][j-1] || dp[i-1][j];
                }                                        //1. 星号让p[j-2]重复0次，考察s(0,i-1)和p(0,j-3)，dp[i][j-2]
            }                                            //2. 星号让p[j-2]重复1次，星号取a与s[i-1]抵消，考察剩余s(0,i-2)和p(0,j-2)，dp[i-1][j-1]
        }                                                //3. 星号让p[j-2]重复多次，从p末尾拿出一个a与s[i-1]抵消，考察剩余s(0,i-2)和p(0,j-1)，dp[i-1][j]
        return dp[m][n];
    }
};
