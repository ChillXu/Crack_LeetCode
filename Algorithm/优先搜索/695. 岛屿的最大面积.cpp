\\
\\简单的dfs
\\
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        if(grid.empty()||grid[0].empty()){  //[[]]
            return 0;
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                maxArea=max(maxArea,dfs(grid,i,j));
            }
        }
        return maxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;//搜索到的地方设定值为0，避免重复搜索
        return 1+dfs(grid,r+1,c)+dfs(grid,r-1,c)+dfs(grid,r,c+1)+dfs(grid,r,c-1);
    }
};
