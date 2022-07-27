//
//dfs
//先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
//构造有向图，1->0，判断图中是否存在环
//visited容器记录节点状态，0未搜索，1搜索中，2已完成
//将当前搜索的节点 u 标记为「搜索中」，遍历该节点的每一个相邻节点 v，如果 v 为「搜索中」，那么我们就找到了图中的一个环，因此是不存在拓扑排序的
//
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses);
        bool valid=true;
        for(auto x:prerequisites){
            edges[x[1]].push_back(x[0]);      // 构造有向图
        }
        for(int i=0;i<numCourses;++i){
            if(visited[i]==0){
                dfs(i,visited,edges,valid);
            }
        }
        return valid;
    }

    void dfs(int Course, vector<int>& visited, vector<vector<int>>& edges, bool& valid){
        visited[Course]=1;        // 搜索中
        for(auto x:edges[Course]){
            if(visited[x]==1){    // 找到环
                valid=false;
                return;
            }
            else if(visited[x]==0){
                dfs(x,visited,edges,valid);
                if(!valid) return;
            }
        }
        visited[Course]=2;        // 已完成
    }
};

//
//bfs
//初始时，所有入度为 0 的节点都被放入队列中
//移除 u 的所有出边，也就是将 u 的所有相邻节点的入度减少 1，如果某个相邻节点 v 的入度变为 0，那么我们就将 v 放入队列中
//如果搜索结束，答案包含n个节点，则存在拓扑排序
//
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree(numCourses);
        for(auto x:prerequisites){
            edges[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> que;
        int visited=0;
        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int cur=que.front();
            que.pop();
            visited++;
            for(auto x:edges[cur]){
                indegree[x]--;
                if(indegree[x]==0){
                    que.push(x);
                }
            }
        }
        return visited==numCourses;
    }
};
