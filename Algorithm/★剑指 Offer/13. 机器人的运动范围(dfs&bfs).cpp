//
//dfs
//每一个可达解仅通过向右和向下即可得到，满足则visited设置为true，不需要回溯
//

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(0,0,k,0,0,m,n,visited);
    }

    int dfs(int i, int j, int k, int si, int sj, int m, int n, vector<vector<bool>>& visited){
        if(i>=m || j>=n || si+sj>k || visited[i][j]) return 0;
        visited[i][j]=true;
        return 1 + dfs(i+1,j,k,(i+1)%10==0?si-8:si+1,sj,m,n,visited)
                 + dfs(i,j+1,k,si,(j+1)%10==0?sj-8:sj+1,m,n,visited);
    }
};
