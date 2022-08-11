/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：

1.每个孩子至少分配到 1 个糖果。
2.相邻两个孩子评分更高的孩子会获得更多的糖果。

请你给每个孩子分发糖果，计算并返回需要准备的最少糖果数目。
*/
//
//考虑整个孩子数组中的任意一个元素x，当它的评分比左边大时需要更新，比右边大时也需要更新（由于已经更新完左规则，此时num[i-1]和num[i]大小不确定）
//遍历两边满足左规则和右规则即可
//注意size<2的初始临界情况
//
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size<2){
            return size;
        }
        vector<int> num(size,1);//容器大小为size，初始值均为1
        for(int i=1;i<size;++i){
            if(ratings[i]>ratings[i-1]){
                num[i]=num[i-1]+1;
            }
        }
        for(int i=size-1;i>0;--i){
            if(ratings[i]<ratings[i-1]){
                num[i-1]=max(num[i-1],num[i]+1);
            }
        }
        return accumulate(num.begin(),num.end(),0); //0为和的初始值
    }
};
