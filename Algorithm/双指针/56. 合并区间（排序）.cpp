//
//先按区间左端点排序，记录当前区间左端点left，不断更新右端点right
//若当前right大于等于下一个区间左端点，则更新右端点
//
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int left;
        int right;
        sort(intervals.begin(),intervals.end());
        //sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){       // 复杂排序会超时！
        //    return a[0]<b[0] || a[0]==b[0] && a[1]<=b[1];
        //});
        for(int i=0;i<intervals.size();++i){
            left=intervals[i][0];
            right=intervals[i][1];
            while(i<intervals.size()-1 && right>=intervals[i+1][0]){
                right=max(right,intervals[i+1][1]);
                ++i;
            }
            ans.push_back({left,right});
        }
        return ans;
    }
};
