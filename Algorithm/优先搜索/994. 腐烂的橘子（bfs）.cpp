//
//bfs
//先将所有已腐烂的橘子入队，同时统计新鲜橘子的个数，按层出队入队
//
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> que;
        int fresh=0;
        int cnt=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2) que.emplace(i,j);     // 注意pair入队写法！！！
                else if(grid[i][j]==1) ++fresh;
            }
        }
        vector<int> dirs{-1,0,1,0,-1};          // 方向写法！！！
        while(!que.empty() && fresh>0){         // fresh>0是必须的！因为最后一次入队时，可能已不存在新鲜橘子，但是队列中还存在最后一批入队的橘子
            int nums=que.size();
            for(int i=0;i<nums;++i){
                auto [x,y]=que.front();         // 取两个元素的写法！！！
                que.pop();
                for(int k=0;k<4;++k){
                    int nx=x+dirs[k];
                    int ny=y+dirs[k+1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        --fresh;
                        que.emplace(nx,ny);
                    }
                }
            }
            ++cnt;
        }
        if(fresh==0) return cnt;
        else return -1;
    }
};
