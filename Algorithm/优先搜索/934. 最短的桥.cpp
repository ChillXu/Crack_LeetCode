//
//dfs先找到第一座岛屿，然后通过bfs将岛屿周围的海洋一层一层搜索，直到找到第二座岛屿的1
//队列：queue<pair<int,int>> points
//
class Solution {
public:
    vector<int> direction{-1,0,1,0,-1};
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> points;
        bool flag=false;
        for(int i=0;i<m;++i){
            if(flag) break;                //只需要找到一座岛屿
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){         //由于需要将离岛屿最近的一层海洋加入队列points，所以仅在找到岛的情况下进行dfs
                    dfs(points,grid,i,j,m,n);
                    flag=true;
                    break;
                }
            }
        }
        int level=0;
        while(!points.empty()){
            ++level;
            int n_points=points.size();
            while(n_points--){
                auto [r,c]=points.front();
                points.pop();
                for(int k=0;k<4;++k){
                    int x=r+direction[k],y=c+direction[k+1];
                    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==2){
                        continue;
                    }
                    if(grid[x][y]==1){
                        return level;
                    }
                    points.push({x,y});        //第二层海洋加入队列
                    grid[x][y]=2;              //已经搜索的海洋标记为2，防止超时
                }
            }
        }
        return 0;
    }

    void dfs(queue<pair<int,int>>& points, vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==2){
            return;
        }
        if(grid[i][j]==0){
            points.push({i,j});
            return;
        }
        grid[i][j]=2;
        for(int k=0;k<4;++k){
            int x=i+direction[k],y=j+direction[k+1];
            dfs(points,grid,x,y,m,n);
        }
    }
};
