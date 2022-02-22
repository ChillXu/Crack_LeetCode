\\
\\按区间结尾从小到大排序，将删除问题转化为选择问题
\\每次选取区间结尾最小且和前一个选择的区间不重叠的区间
\\
\\"贪心问题记得考虑是否需要排序！！！"
\\
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<2){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>&b){ //Lambda函数
            return a[1]<b[1];
        });
        int total=0;
        int prev=intervals[0][1];
        for(int i=1;i<n;++i){
            if(intervals[i][0]<prev){
                ++total;
            }
            else{
                prev=intervals[i][1];
            }
        }
        return total;
    }
};
