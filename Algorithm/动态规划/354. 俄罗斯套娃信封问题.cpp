//
//将所有的信封按照 w 值第一关键字升序、h 值第二关键字降序进行排序
//排序之后转化为最长严格单调增子序列问题
//二分查找+动态规划
//
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](const auto& e1,const auto& e2){
            return e1[0]<e2[0] || (e1[0]==e2[0] && e1[1]>=e2[1]);
        });
        vector<int> f={envelopes[0][1]};
        for(int i=1;i<n;++i){
            if(envelopes[i][1]>f.back()){
                f.push_back(envelopes[i][1]);
            }
            else{
                auto it=lower_bound(f.begin(),f.end(),envelopes[i][1]);     // 找到f中比envelopes[i][1]严格小的最大元素
                *it=envelopes[i][1];
            }
        }
        return f.size();
    }
};

//
//暴力动态规划会超时
//
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](const auto& e1,const auto& e2){
            return e1[0]<e2[0] || (e1[0]==e2[0] && e1[1]>=e2[1]);
        });
        vector<int> dp(n,1);
        for(int i=1;i<n;++i){        //找以envelopes[i]结尾的最长单调增子序列
            for(int j=0;j<i;++j){     
                if(envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);   
                }
            }
        }
        return *max_element(dp.begin(),dp.end());  //是以envelopes[i]结尾的最长单调增子序列,不是到envelopes[i]为止的最长单调增子序列
    }
};
