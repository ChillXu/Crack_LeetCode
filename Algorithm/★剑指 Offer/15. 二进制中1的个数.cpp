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
//n&(n-1)每次会将n最右边的第一个1变成0
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
