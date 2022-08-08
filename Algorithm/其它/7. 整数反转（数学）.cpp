//
//可以不用队列直接取余乘十
//ans*10+digit≤INT_MAX  （2^31−1=2147483647）
//rev⋅10+digit≤⌊INT_MAX/10⌋*10+7
//(ans−⌊INT_MAX/10⌋)*10≤7−digit （如果输入也是10位数，那末尾一定小于等于2，即此时digit<=2）
//ans>=⌊INT_MAX/10⌋时满足上式条件
//
//***假设环境不允许存储 64 位整数***
//
class Solution {
public:
    int reverse(int x) {
        queue<int> que;
        int ans=0;
        //bool sign=false;
        //if(x<0) sign=true;
        while(x){
            que.push(x%10);
            x/=10;
        }
        while(que.front()==0){
            que.pop();
        }
        while(!que.empty()){
            if(ans>INT_MAX/10 || ans<INT_MIN/10){   // 精髓！！
                return 0;
            }
            ans*=10;
            ans+=que.front();
            que.pop();
        }
        return ans;
    }
};



//
//
//
class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x){
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            int digit=x%10;
            x/=10;
            ans=ans*10+digit;
        }
        return ans;
    }
};
