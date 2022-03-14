//
//用visited记录已访问的城市，主函数完成一次dfs即为一个省
//
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(), count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;++i){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
        visited[i]=true;
        for(int k=0;k<isConnected.size();++k){
            if(isConnected[i][k]==1 && !visited[k]){
                dfs(isConnected,k,visited);
            }
        }
    }
};
