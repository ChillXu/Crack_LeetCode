class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        //if(candidates.empty()) return ans;
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,ans,cur,target,0);
        return ans;
    }

    void backtracking(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& cur, int target, int sum){
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=0;sum+candidates[i]<=target;++i){
            cur.push_back(candidates[i]);
            backtracking(candidates,ans,cur,target,sum+candidates[i]);
            cur.pop_back();
        }
        return;
    }
};
