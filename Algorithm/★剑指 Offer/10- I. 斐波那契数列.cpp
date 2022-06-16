//
//
//
class Solution {
public:
    int fib(int n) {
        int MOD=1000000007;
        if(n<2) return n;
        int p=0,q=1,r;
        for(int i=1;i<n;++i){
            r=(p+q)%MOD;
            p=q;
            q=r;
        }
        return r;
    }
};
