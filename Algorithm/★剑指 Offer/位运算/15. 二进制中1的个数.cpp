//
//位运算
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=0;i<32;++i){
            if((n&1)==1){   //运算符的优先级!!!
                cnt++;
            }
            n=n>>1;
        }   
        return cnt;
    }
};


//
// n&(n-1) 每次会将 n 最右边的第一个 1 变成 0
// n 二进制最高位为 1，其余所有位为 0；n−1 二进制最高位为 0，其余所有位为 1，可以用来判断一个数是否为2的幂
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            n&=n-1;
            cnt++;
        }
        return cnt;
    }
};
