\\
\\二分查找
\\
class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x,mid;
        int ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if((long long)mid*mid<=x){      //用乘法需要考虑溢出情况
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

\\
\\牛顿迭代法 y=x^2-a=0
\\过x0做y的切线，y=f(x0)+f'(x0)(x-x0) -> x=x0-f(x0)/f'(x0)
\\
class Solution {
public:
    int mySqrt(int a) {
        long x=a;
        while(x*x>a){
            x=(x+a/x)/2;
        }
        return x;
    }
};
