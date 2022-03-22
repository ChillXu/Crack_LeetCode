//
//状态机，三个状态即可，s1多余
//详解：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<int> buy(n,0),sell(n,0),rest(n,0);
        buy[0]=-prices[0];       //！！！初始化
        for(int i=1;i<n;++i){
            buy[i]=max(buy[i-1],rest[i-1]-prices[i]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
            rest[i]=max(rest[i-1],sell[i-1]);
        }
        return max(sell[n-1],rest[n-1]);
    }
};
