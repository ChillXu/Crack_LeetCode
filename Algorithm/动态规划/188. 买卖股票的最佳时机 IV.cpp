//
//状态机
//buy[j]是持有第j次交易的股票时（可以是今天买的，也可以是以前买的）获取的最大利益；sell[j]是不持有第j次交易的股票时（可以是今天卖的，也可以是以前卖的）获取的最大利益
//
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        if(k>=n-1) return maxProfitUnlimitied(prices);
        vector<int> buy(n+1,INT_MIN),sell(n+1,0);      //sell[0]=0,buy[1]=max(buy[1],sell[0]-price[0]);
        for(int i=0;i<n;++i){
            for(int j=1;j<=k;++j){
                buy[j]=max(buy[j],sell[j-1]-prices[i]);  //当i更新时，sell[j-1]-prices[i]可能取到比之前更大的值
                sell[j]=max(sell[j],buy[j]+prices[i]);   //当i更新时，buy[j]+prices[i]可能卖出更高的价格
            }
        }
        return sell[k];
    }

    int maxProfitUnlimitied(vector<int> prices){
        int n=prices.size();
        int maxp=0;
        for(int i=1;i<n;++i){
            if(prices[i]>prices[i-1]){
                maxp+=prices[i]-prices[i-1];
            }
        }
        return maxp;
    }
};
