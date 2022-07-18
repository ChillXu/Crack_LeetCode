//
//快速幂
//

class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        long pow=n;
        if(n<0){
            pow=(long)-1*n;  // -2147483648=-2^31，2^31会导致int溢出，int最大值为2^31-1
            x=1./x;
        }
        while(pow){
            if((pow&1)==1){
                res*=x;
            }
            pow=pow>>1;
            x*=x;
        }
        return res;
    }
};
