/*
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。

你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
*/
//
//贪心先排序，外循环小朋友，先把胃口小的满足了，这样饼干数组只能继续向后遍历
//因为小朋友的胃口是逐渐增大的，只有后面的更大的饼干才能满足
//
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int num=0,index=0;
        for(int i=0;i<g.size();++i){
            for(int j=index;j<s.size();++j){
                if(g[i]<=s[j]){
                    num++;
                    index=j+1;
                    break;    //应该是break,不是continue！！
                }
            }
        }
        return num;
    }
};


//
//解法二，在while循环一直j++，一但出循环说明有满足的，则计数count++，j则在外循环继续自增
//
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChildren = g.size(), numOfCookies = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < numOfChildren && j < numOfCookies; i++, j++) {
            while (j < numOfCookies && g[i] > s[j]) {
                j++;
            }
            if (j < numOfCookies) {
                count++;
            }
        }
        return count;
    }
};

