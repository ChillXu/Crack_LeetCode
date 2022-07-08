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


//
//快速幂
//

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        long res=1;
        int pow=n/3;
        int last=n%3;
        if(last==1) return (4*fastpower(3,pow-1,res))%1000000007;     //fastpower返回值乘以4可能会溢出，需要取模
        else if(last==2) return (2*fastpower(3,pow,res))%1000000007;
        else return (fastpower(3,pow,res))%1000000007;
    }

    long fastpower(long base, int pow, long res){
        while(pow>0){
            if((pow&1)==1){
                res=res*base%1000000007;  //res可能会溢出
            }
            pow=pow>>1;
            base=base*base%1000000007;  //base可能会溢出，用long
        }
        return res;
    }
};
