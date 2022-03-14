//
//组合回溯
//
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb(k,0);
        backtracking(comb,0,n,k,1,ans);   //pos初始值为1！
        return ans;
    }

    void backtracking(vector<int>& comb, int count, int n, int k, int pos, vector<vector<int>>& ans){
        if(count==k){
            ans.push_back(comb);
            return;
        }
        for(int i=pos;i<=n;++i){
            comb[count++]=i;
            backtracking(comb,count,n,k,i+1,ans);   //i+1不是pos+1,写成后者在回溯的时候无法正确添加之后的数组元素到comb
            count--;
        }
    }
};
