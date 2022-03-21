//
//暴力解法，双重循环会超时
//只遍历一遍，维护两个值，当前最低价格和当前最大收益
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0,minprice=INT_MAX;
        for(int i=0;i<n;++i){
            minprice=min(minprice,prices[i]);
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};
