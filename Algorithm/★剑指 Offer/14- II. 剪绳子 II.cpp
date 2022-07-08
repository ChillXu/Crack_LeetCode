//
//尽可能将绳子以长度 3 等分为多段时，乘积最大！
//循环求余
//

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        long res=1;   //会溢出，需要用到long
        while(n>4){
            res*=3;
            res%=1000000007;
            n-=3;
        }
        return n*res%1000000007;
    }
};
