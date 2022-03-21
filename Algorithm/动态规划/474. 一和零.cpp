//
//多维费用的 0-1 背包问题
//需要空间压缩
//
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(const string& s:strs){
            auto [c0,c1]=count(s);
            for(int i=m;i>=c0;--i){        //逆向遍历
                for(int j=n;j>=c1;--j){
                    dp[i][j]=max(dp[i][j],dp[i-c0][j-c1]+1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int,int> count(const string& s){     //或者直接调用容器的count函数，count(strs.begin(),strs.end(),'0')
        int c0=s.length(),c1=0;
        for(const char& c:s){
            if(c=='1'){
                --c0;
                ++c1;
            }
        }
        return make_pair(c0,c1);
    }
};


/* 11-15错误写法：
            for(int i=m;i>=1;--i){             //c0或c1取值小于等于0时，二者不等价
                for(int j=n;j>=1;--j){
                    if(i>=c0 && j>=c1){
                        dp[i][j]=max(dp[i][j],dp[i-c0][j-c1]+1);
                    }
                }
            }
