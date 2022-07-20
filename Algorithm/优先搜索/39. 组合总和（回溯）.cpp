//
//[2,3,6,7] 7
//[[2,2,3],[7]]
//
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        //if(candidates.empty()) return ans;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,ans,cur,target,0,0);
        return ans;
    }

    void backtracking(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& cur, int target, int sum, int index){
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=index;i<candidates.size() && sum+candidates[i]<=target;++i){      // i<candidates.size()不能少，否则递归的第一层会数组访问溢出
            cur.push_back(candidates[i]);
            backtracking(candidates,ans,cur,target,sum+candidates[i],i);            // index很关键，防止相同组合的重复排列，如[2,2,3]和[2,3,2]
            cur.pop_back();
        }
        return;
    }
};
