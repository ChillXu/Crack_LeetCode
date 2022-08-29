//
//题目：给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
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
