//
//15.二进制中1的个数
//
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;++i){
            ans.push_back(countOne(i));
        }
        return ans;
    }
    int countOne(int n){
        int cnt=0;
        while(n){
            n&=n-1;
            cnt++;
        }
        return cnt;
    }
};


//
//动态规划
//用highBits记录最高位，避免重复计算
//
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int highBits=0;
        for(int i=1;i<=n;++i){
            if((i&(i-1))==0){     // 此时i是2的整数次幂，最高位为1，其余位为0
                highBits=i;
            }
            ans[i]=ans[i-highBits]+1;   // ans[i]只与ans[i-highBits]相差一个最高位的1
        }
        return ans;
    }
};
