\\
\\转换一下思维，如果直接对所有位置进行dfs，复杂度会很高，且不易判断是否能入海
\\可以从太平洋和大西洋出发，反向能走到的地方，二者求交集
\\
class Solution {
public:
    vector<int> directions{-1,0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()){
            return {};
        }
        int m=heights.size(), n=heights[0].size();
        vector<vector<bool>> can_reach_p(m,vector<bool>(n,false));
        vector<vector<bool>> can_reach_a(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            dfs(heights,can_reach_p,i,0);
            dfs(heights,can_reach_a,i,n-1);
        }
        for(int i=0;i<n;++i){
            dfs(heights,can_reach_p,0,i);
            dfs(heights,can_reach_a,m-1,i);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(can_reach_p[i][j]&&can_reach_a[i][j]){
                    ans.push_back(vector<int>{i,j});    \\注意容器的写法，不是{i,j}
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int r, int c){
        if(can_reach[r][c]){
            return;
        }
        can_reach[r][c]=true;
        int x,y;
        for(int i=0;i<4;++i){
            x=r+directions[i],y=c+directions[i+1];
            if(x>=0 && y>=0 && x<heights.size() && y<heights[0].size() && heights[r][c]<=heights[x][y]){
                dfs(heights,can_reach,x,y);
            }
        }

    }
};
