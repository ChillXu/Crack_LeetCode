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


//
//bfs
//利用队列，先将初始点(0,0)加入队列，出队判断是否为可达解，是则将其相邻右边和下边加入队列，否则跳过
//

class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<vector<int>> que;
        que.push({0,0,0,0});
        int res=0;
        while(!que.empty()){
            vector<int> x=que.front();
            que.pop();
            int i=x[0],j=x[1],si=x[2],sj=x[3];
            if(i>=m || j>=n || si+sj>k || visited[i][j]) continue;
            visited[i][j]=true;
            res++;
            que.push({i+1,j,(i+1)%10==0?si-8:si+1,sj});
            que.push({i,j+1,si,(j+1)%10==0?sj-8:sj+1});
        }
        return res;
    }
};
